#include "elfloader.h"
#include "fs/file.h"
#include "status.h"
#include <stdbool.h>
#include "memory/memory.h"
#include "memory/heap/kheap.h"
#include "string/string.h"
#include "memory/paging/paging.h"
#include "kernel.h"
#include "config.h"


const char* elf_signature[] = {0x7f, 'E', 'L', 'F'};

static bool elf_valid_signature(void* buffer)
{
    return memcmp(buffer, (void*) elf_signature, sizeof(elf_signature)) == 0;
}

static bool elf_valid_class(struct elf_header* header)
{
    // We only support 32 bit binaries.
    return header->e_ident[EI_CLASS] == ELFCLASSNONE || header->e_ident[EI_CLASS] == ELFCLASS32;
}

static bool elf_valid_encoding(struct elf_header* header)
{
    return header->e_ident[EI_DATA] == ELFDATANONE || header->e_ident[EI_DATA] == ELFDATA2LSB;
}

static bool elf_is_executable(struct elf_header* header)
{
    return header->e_type == ET_EXEC && header->e_entry >= PEACHOS_PROGRAM_VIRTUAL_ADDRESS;
}

static bool elf_has_program_header(struct elf_header* header)
{
    return header->e_phoff != 0;
}

void* elf_memory(struct elf_file* file)
{
    return file->elf_memory;
}

struct elf_header* elf_header(struct elf_file* file)
{
    return file->elf_memory;
}

struct elf32_shdr* elf_sheader(struct elf_header* header)
{
    return (struct elf32_shdr*)((int)header+header->e_shoff);
}

struct elf32_phdr* elf_pheader(struct elf_header* header)
{
    if(header->e_phoff == 0)
    {
        return 0;
    }

    return (struct elf32_phdr*)((int)header + header->e_phoff);
}

struct elf32_phdr* elf_program_header(struct elf_header* header, int index)
{
    return &elf_pheader(header)[index];
}

struct elf32_shdr* elf_section(struct elf_header* header, int index)
{
    return &elf_sheader(header)[index];
}

char* elf_str_table(struct elf_header* header)
{
    return (char*) header + elf_section(header, header->e_shstrndx)->sh_offset;
}

void* elf_virtual_base(struct elf_file* file)
{
    return file->virtual_base_address;
}

void* elf_virtual_end(struct elf_file* file)
{
    return file->virtual_end_address;
}

void* elf_phys_base(struct elf_file* file)
{
    return file->physical_base_address;
}

void* elf_phys_end(struct elf_file* file)
{
    return file->physical_end_address;
}

int elf_validate_loaded(struct elf_header* header)
{
    return (elf_valid_signature(header) && elf_valid_class(header) && elf_valid_encoding(header) && elf_has_program_header(header)) ? PEACHOS_ALL_OK : -EINVARG;
}