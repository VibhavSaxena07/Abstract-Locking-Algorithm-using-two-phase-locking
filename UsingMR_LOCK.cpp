#include <iostream>
#include <string>
#include <functional>
#include "tbb/concurrent_unordered_set.h"
#include "mrlock.h"
#include "bitset.h"

using namespace std;
using namespace tbb;


class MyClass
{
public:
    
    MyClass(int key) : key(key){}
    int key;
    int getA() const { return key; }
    friend ostream& operator << (ostream& ost, const MyClass& k)
    {
        ost << "A: " << k.getA()  << endl;
        return ost; 
    }
};

struct my_hasher
{
    size_t operator()(const MyClass& val)const
    {
        
        std::hash<int> hash_int;
        size_t hashval = hash_int(val.getA());
        return hashval;
    }
};

struct my_equalto 
{
    bool operator()(const MyClass& one, const MyClass& two) const
    {
        return (one.getA() == two.getA());
    }
};

concurrent_unordered_set<MyClass, my_hasher, my_equalto> S;
concurrent_unordered_set<MyClass, my_hasher, my_equalto>::iterator cacheit;

void Lock(MyClass &k1, MyClass &k2, MyClass &k3, MyClass &k4, MyClass &k5, int x)
{
    std::cout << "\nThread " << x << " is trying to lock \n"; 
    uint32_t set[5];
    set[0] = uint32_t(k1.key);
    set[1] = uint32_t(k2.key);
    set[2] = uint32_t(k3.key);
    set[3] = uint32_t(k4.key);
    set[5] = uint32_t(k5.key);
    MRLock<uint32_t> *mrlck = new MRLock<uint32_t>(5);
    mrlck->Lock(set);
    std::cout << k1.key <<"," << k2.key <<"," << k3.key <<"," << k4.key <<","<< k5.key << " ARE WAITING FOR LOCKS " << std::endl;
    std::cout << k1.key <<"," << k2.key <<"," << k3.key <<"," << k4.key <<","<< k5.key << "GOT LOCKS!!" << std::endl;
    mrlck->Unlock(set);
    std::cout << k1.key <<"," << k2.key <<"," << k3.key <<"," << k4.key <<","<< k5.key << " ARE UNLOCKED " << std::endl;
    S.insert(k1.key);
    S.insert(k2.key);
    S.insert(k3.key);
    S.insert(k4.key);
    S.insert(k5.key);
}

int main()
{
    MyClass key1(1);
    MyClass key2(2);
    MyClass key3(3);
    MyClass key4(4);
    MyClass key5(5);
    MyClass key6(6);
    MyClass key7(7);
    MyClass key8(8);
    MyClass key9(9);
    MyClass key10(10);
    MyClass key11(11);
    MyClass key12(12);
    MyClass key13(13);
    MyClass key14(14);
    MyClass key15(15);
    MyClass key16(16);
    MyClass key17(17);
    MyClass key18(18);
    MyClass key19(19);
    MyClass key20(20);   
    MyClass key21(21); 
    MyClass key22(22); 
    MyClass key23(23); 
    MyClass key24(24); 
    MyClass key25(25); 
    

    
    int arraylist[25];
    
    std::thread t1,t2,t3,t4,t5;
   
        t1 = std::thread(Lock, std::ref(key1), std::ref(key2), std::ref(key3), std::ref(key4), std::ref(key5), 1);
        t2 = std::thread(Lock, std::ref(key6), std::ref(key7), std::ref(key8), std::ref(key9), std::ref(key10), 2);
        t3 = std::thread(Lock, std::ref(key11), std::ref(key12), std::ref(key13), std::ref(key14), std::ref(key15), 3);
        t4 = std::thread(Lock, std::ref(key16), std::ref(key17), std::ref(key18), std::ref(key19), std::ref(key20), 4);
        t5 = std::thread(Lock, std::ref(key21), std::ref(key22), std::ref(key23), std::ref(key24), std::ref(key25), 5);
    
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();

    cout <<"Unordered set is \n";
    cacheit = S.begin();    
    while (cacheit != S.end())
    {
        cout << *cacheit ;
        ++cacheit;
    }

    return 0;

}
