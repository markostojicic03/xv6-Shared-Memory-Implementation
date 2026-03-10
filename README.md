# xv6 Shared Memory Implementation

## Project Overview
This project involves extending the xv6 operating system to support shared memory between different processes. The implementation introduces global shared memory objects, allowing multiple processes to access and modify the same memory region efficiently. 

The core objective is to integrate these new memory management capabilities seamlessly without disrupting the existing performance and stability of the xv6 system.

## Implemented System Calls

The following system calls were added to the xv6 kernel to manage the lifecycle and mapping of shared memory objects:

### 1. shm_open
* **Signature:** `int shm_open(char *name);`
* **Description:** Opens an existing shared memory object or creates a new one with the specified name.
* **Returns:** A shared memory descriptor (integer) on success, or -1 if the operation fails.

### 2. shm_trunc
* **Signature:** `int shm_trunc(int shm_od, int size);`
* **Description:** Allocates or resizes the physical memory associated with the shared memory descriptor `shm_od` to the specified `size`.
* **Returns:** 0 on success, or -1 on failure.

### 3. shm_map
* **Signature:** `int shm_map(int shm_od, void **va, int flags);`
* **Description:** Maps the physical pages of the shared memory object identified by `shm_od` into the calling process's virtual address space. The resulting virtual address is stored in the pointer provided by `va`.
* **Returns:** 0 on successful mapping, or -1 if the mapping fails.

### 4. shm_close
* **Signature:** `int shm_close(int shm_od);`
* **Description:** Closes the shared memory descriptor for the calling process. If the calling process is the last one attached to this shared memory object, the associated physical memory is properly freed.
* **Returns:** 0 on successful closure, or -1 if an error occurs.

## Technical Implementation
* **Kernel Modifications:** The project requires significant modifications to the xv6 kernel's memory management subsystem to track global shared memory objects and map physical pages to multiple virtual address spaces simultaneously.
* **Error Handling:** Robust error checking is implemented across all new system calls to return -1 for invalid descriptors, mapping conflicts, or memory allocation failures.
* **Process Isolation:** While enabling memory sharing, the system ensures that other memory segments (such as the heap and stack) remain strictly isolated and protected.

## Build and Testing
This project is managed and submitted via GitHub Classroom.

1. Clone the repository containing the modified xv6 source code.
2. Compile and run the operating system using the provided Makefile by typing:
   `make qemu`
3. Use the provided user-space testing program from the course materials to verify that data written to a shared memory segment by one process can be successfully read by another process.

---
*Developed as a project for the Operating Systems course.*
