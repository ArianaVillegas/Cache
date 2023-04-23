# Complexity Analysis

| Data Structure | Operation | Complexity |
| :--: | :--: | :--: |
| unordered_map | [] | O(1) |
| unordered_map | find | O(1) |
| unordered_map | end | O(1) |
| unordered_map | erase(itr) | O(1) |
| list | size | O(1) |
| list | begin | O(1) |
| list | end | O(1) |
| list | front | O(1) |
| list | back | O(1) |
| list | push_front | O(1) |
| list | pop_front | O(1) |
| list | push_back | O(1) |
| list | pop_back | O(1) |

## Space

Space complexity is constant because the data structure has a maximum size that is defined when it is created.

## Time Complexity

* InsertKeyValuePair: For this function, there are two cases,
   - The key is already in the structure: First, a hash is used to access the iterator that has the key/value pair in the list ([]). Then, the iterator is used to change the value in the list, the previous operations are constant, therefore this case is O(1).
   - The key is not in the structure:
      - If the structure is full, we remove the last element of the list, and with the key from the list we also remove it in the hash. O(1)
      - The new key/value pair is added to the beginning of the list (push_front), then we save this value in the hash ([]), to access it we use (front), and insert the pair into the hash ([]). O(1)
* GetValueFromKey: Two cases
   - If the key is not in the hash, we return nullopt. O(1)
   - If the key is, we remove it from the position it is in (erase), and insert it at the beginning of the list (push_front), and update the value in the hash ([]). Finally, we return the value of the key/value pair. O(1)
* GetMostRecentKey: We access the first pair in the list and take the value (front). O(1)

# Time comparison table

| Size | LRU | FIFO | LIFO |
| :--: | :--: | :--: | :--: |
| 10000 | 0.016224 | 0.015059 | 0.014854 |
| 100000 | 0.113235 | 0.105974 | 0.094090 |
| 1000000 | 1.25813 | 0.87822 | 0.89499 |
| 10000000 | 10.0824 | 9.81382 | 10.2575 |
| 100000000 | 123.058 | 119.257 | 113.550 |
