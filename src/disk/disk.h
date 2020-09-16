#ifndef DISK_H
#define DISK_H

int disk_read_sector(int lba, int total, void* buf);

#endif