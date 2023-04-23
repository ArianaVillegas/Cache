# Cache Memory

This repository contains an implementation of a cache memory with different replacement policies. The cache memory is a type of high-speed memory that is used to store frequently accessed data, which can be quickly retrieved without having to access the slower main memory. 

## Replacement Policies

A replacement policy is a mechanism used to determine which data should be evicted from the cache memory when it is full and new data needs to be loaded. The three policies implemented in this repository are:

* LRU (Last Recently Used): This policy selects the data that was least recently used for eviction. It tries to predict which data will be used in the near future by assuming that the data that was accessed recently is more likely to be accessed again.

* FIFO (First In First Out): This policy selects the data that was loaded into the cache memory first for eviction. It follows the assumption that the data that was loaded first is less likely to be needed in the future compared to the data loaded later.

* LIFO (Last In First Out): This policy selects the data that was loaded into the cache memory last for eviction. It follows the assumption that the data that was loaded last is more likely to be accessed again in the near future compared to the data loaded earlier.
