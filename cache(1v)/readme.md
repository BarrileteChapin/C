# Problem Definition
  
In this project, we consider byte addresses and byte addressable cache systems. 
Give a cache with the M-bit address bits, B-byte block size, E cache sets, and using A-way set associativity.

There are 𝑂 = log2 𝐵 bits offset, and we need to select 𝐾 = log2 𝐸 bits among upper (M-O) address bits for indexing the cache. There are totally C(𝑀−𝑂/𝐾) possible valid indexing schemes.Our job is to (i) implement the NRU
replacement policy and the LSB indexing scheme and (ii) find a valid indexing scheme with minimal cache misses.

## Sample INPUT (inside program):
      Address_bits: 8
      Block_size: 4
      Cache_sets: 4
      Associativity: 2

      Addresses:       
      00000000
      00010000
      00100000
      00000000
      00101100
      00000000
      00101100

## Sample OUTPUT: 

    Offset bit count: 2
    Indexing bit count: 2
    Indexing bits: 3 2

    00000000 miss
    00010000 miss
    00100000 miss
    00000000 miss
    00101100 miss
    00000000 hit
    00101100 hit
  
  Total cache miss count: 5
  
-- Note: this is not the final version of the project :)
