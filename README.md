# Abstract-Locking-Algorithm-using-two-phase-locking
 Implement abstract locking algorithm using two phase locking. I am using std::lock as it implements two phase locking. For implementing this I have taken 25 keys and then locking/unlocking in batches of 5 and locking 5 keys in one time and implementing two- phase locking.
So I have taken a 2D array and created 5 batches of 5 keys. I am sending 5 keys at one time and trying to lock it and if the lock is acquired unlock function is called.
5 threads are taken for accessing 25 keys in batches of 5. CLASS – MyClass-
I declared a class “ MyClass” which initializes “id” through which we can assign IDs to the generated keys.
It also declares
std::mutex m;
it is a mutual exclusion lock used to lock/unlock the keys in respective
functions.
LOCK METHOD - “LOCK”
It simply locks 5 keys passed to it using std::lock and after the lock is acquired “unlock” function is called.
In this function we are using io_mutex to control the threads accessing the locks.
This mutex ensures that only one thread is accessing the thread at moment
UNLOCK METHOD – “unlock”-
In unlock method also io_mutex is used to control thread entry and then we are unlocking each key using key. Unlock();
    
So I am implementing two phase locking in this by trying to lock batch of 5 keys by locking 1 key at a time and then whole batch is locked. We have a separate function for locking and unlocking the keys.
By locking the batches of 5 keys we complete locking-unlocking of 25 keys.
MAIN() FUNCTION -
In main function we declare a 2D array of 5 x 5 which is basically implementing the idea of assigning 5 keys in each of the 5 batches.
We initialize the values of key and then passing 5 keys at a time through single thread.
In total 5 threads are taken (t1,t2,t3,t4,t5) and each thread is assigned with 5 keys.
OUTPUT-
In the output we have printed the locking and unlocking of keys with their respective “ids” and showed how they are first getting locked and after the whole batch is locked the batch is unlocked and the another batch enters the Locking function.
Example -
>>g++Q1.cpp -ltbb -std=c++11 -fpermissive -lpthread
>>./a.out
Thread 2 is trying to lock
2,15,24,14 and 92 are waiting for locks Thread 2 Acquiring the lock
Key 1(2) got the lock
Key 2(15) got the lock
Key 3(24) got the lock
Key 4(14) got the lock
Key 5(92) got the lock
2,15,24,14 and 92 got locks
GOT ALL LOCKS!!
Thread 2 is unlocking
  2,15,24,14 and 2 IS UNLOCKED 15 IS UNLOCKED 24 IS UNLOCKED 14 IS UNLOCKED 92 IS UNLOCKED
92 are waiting for locks
