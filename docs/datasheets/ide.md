# vim
## vim-cmake
:CMakeGenerate
:CMakeBuild


# C++ 
## data race
When an evaluation of an expression writes to a memory location and another evaluation reads or modifies the same memory location, the expressions are said to conflict. A program that has two conflicting evaluations has a data race unless

1. both evaluations execute on the same thread or in the same signal handler, or
2. both conflicting evaluations are atomic operations (see std::atomic), or
3. one of the conflicting evaluations happens-before another (see std::memory_order)
If a data race occurs, the behavior of the program is undefined.

- obstruction freedom
An algorithm is obstruction-free if at any point, a single thread executed in isolation (i.e., with all obstructing threads suspended) for a bounded number of steps will complete its operation.
Some obstruction-free algorithms use a pair of "consistency markers" in the data structure. Processes reading the data structure first read one consistency marker, then read the relevant data into an internal buffer, then read the other marker, and then compare the markers. The data is consistent if the two markers are identical. Markers may be non-identical when the read is interrupted by another process updating the data structure. In such a case, the process discards the data in the internal buffer and tries again.
- lock freedom

Lock-freedom allows individual threads to starve but guarantees system-wide throughput. An algorithm is lock-free if, when the program threads are run for a sufficiently long time, at least one of the threads makes progress (for some sensible definition of progress). All wait-free algorithms are lock-free.


- lock-free vs lockless
lock-free: 強調以系統的觀點來看，只要執行足夠長的時間，至少會有一個執行緒會有進展 (progress)
lockless: 避免使用 lock 達到安全無誤地操作共用資料

cas + loop lockless，但不是 lock-free


想像一個情況: 在使用 mutex 時，若其中一個執行緒在釋放 lock 之前被系統 preempt，則需要同一個資源的其他執行緒會無法繼續，直到原本的執行緒恢復執行完畢

若系統 kill 執行緒，則整個程式就完全無法再繼續前進
分類:
wait-free 是 non-blocking 之中強度最高的，它保證所有的指令可以 bound 在某個時間內完成，也就是所有的執行緒經過一段足夠的時間後，一定會有所進展
lock-free 稍微弱一點，它允許部份執行緒被暫停，但仍然保證整體程式的其他部份會有進展
最差的情況下，就算只有一個執行緒在執行，其他所有執行緒都在等待，仍然屬於 lock-free
obstruction-free，non-blocking 中最弱的，當有其他執行緒在動的時候，可能會 livelock
根據定義，所有 wait-free 都屬於 lock-free
