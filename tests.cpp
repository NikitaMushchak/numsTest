#include "whattotest.cpp"
#include <bitset>
#include "gtest/gtest.h"
#include <future>
#include <stack>
//#include "H:\googletest-release-1.10.0\googletest\include\gtest\gtest.h"


//TEST(isPrimeTest, Zero) {
//    ASSERT_TRUE(!isPrime(0));
//    ASSERT_TRUE(!isPrime(-0));
//   
//}
//
//TEST(isPrimeTest, PositiveNos) {
//    ASSERT_TRUE(!isPrime(1));
//    ASSERT_TRUE(isPrime(2));
//    ASSERT_TRUE(isPrime(3));
//    ASSERT_TRUE(!isPrime(4));
//    ASSERT_TRUE(isPrime(5));
//    ASSERT_TRUE(!isPrime(6));
//    ASSERT_TRUE(isPrime(7));
//    ASSERT_TRUE(!isPrime(8));
//    ASSERT_TRUE(!isPrime(9));
//    ASSERT_TRUE(isPrime(109));
//    ASSERT_TRUE(!isPrime(111));
//}

//TEST(asyncTest, firstii){
//    std::cout << "Main Id task : " << std::this_thread::get_id() << std::endl;
//
//    std::queue<std::future<bool> > queue;
//
//    for (int it = 0; it < 10; ++it)
//        queue.push(std::async(ftask, it));
//
//    while (!queue.empty()) {
//        queue.front().wait();
//        queue.pop();
//    }
//    std::cout << "Main finished!";
//}

//TEST(asynclaunchTest, secondii) {
//    std::cout << "Main Id task : " << std::this_thread::get_id() << std::endl;
//
//    std::queue<std::future<bool> > queue;
//
//    for (int it = 0; it < 10; ++it)
//        queue.push( std::async(std::launch::deferred,ftask, it) );
//
//    bool result = false;
//    while (!queue.empty()) {
//        auto& task = queue.front();
//        result = task.get();
//        queue.pop();
//    }
//    std::cout << "Main finished!";
//}

//TEST(asynclaunchTest, secondii) {
//    std::cout << "Main Id task : " << std::this_thread::get_id() << std::endl;
//
//    std::queue<std::future<bool> > queue;
//
//    for (int it = 0; it < 10; ++it)
//        queue.push(std::async(std::launch::async, [it] {return ftask(it); }));
//
//    bool result = false;
//    while (!queue.empty()) {
//        auto& task = queue.front();
//        result = task.get();
//        queue.pop();
//    }
//    std::cout << "Main finished!";
//}

//TEST(asynclaunchTest2, objii) {
//    std::cout << "Main Id task : " << std::this_thread::get_id() << std::endl;
//
//    std::queue<std::future<bool> > queue;
//
//    for (int it = 0; it < 10; ++it) {
//        Item item;
//        auto a = std::async(std::launch::async, [&item] {item.start(); });
//        queue.push(a.get());
//        
//    }
//
//    bool result = false;
//    while (!queue.empty()) {
//        auto& task = queue.front();
//        result = task.get();
//        queue.pop();
//    }
//    std::cout << "Main finished!";
//}

TEST(asynclaunchTest2, objii) {
    std::cout << "Main Id task : " << std::this_thread::get_id() << std::endl;

    Item item;
    auto fut = std::async(std::launch::async, [&item] {
        item.start();
        });
    fut.get();

    std::cout << "finished : " << std::endl;
}
struct ListNode {
  

    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    void Push_Back(ListNode *&plist,int number) {
        
        if (plist == nullptr) {
            plist = new ListNode(number);
            
        }
        else {
            
            plist->next = new ListNode(number);
            plist = plist->next;
        }
        
    }

    void Print_List(ListNode list) {
        int iterr = 0;
        ListNode* current = list.next;
        while (current) {
            std::cout << "list member # " << iterr << " = " << current->val << std::endl;
            current = current->next;
            iterr++;
        }

    }

    void Push_Back(ListNode**& tlist1, int number) {
        (*tlist1) = new ListNode(number);
        tlist1 = &((*tlist1)->next);
    }

    void Print_List(ListNode**& itlist) {
        int iter = 0;
        while ((*itlist))
        {
            std::cout << "list element #" << iter << " : " << (*itlist)->val << std::endl;
            iter++;
            *itlist = (*itlist)->next;
        }
    }
};
 

int main(int argc, char **argv) {
    
    ListNode *list1(0);

    ListNode** tlist1 = &list1;
    for (int i = 0; i < 10; ++i) {
        (*tlist1)->Push_Back(tlist1, i);
        
    }
   
    ListNode** itlist = &list1;
    list1->Print_List(itlist);
   

    ListNode list(0);
    
    ListNode* pList = &list;

    for (int i = 0; i < 10;i++) {
        list.Push_Back(pList, i);
    }
    list.Print_List(list);
   
    

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//int main() {
//    int num_freq = 0;
//    std::string previuos = "";
//    std::string currentk;
//    while (std::cin >> currentk)
//    {
//        ++num_freq;
//	if (previuos == currentk) {
//            std::cout << "repeating word : " << currentk<<" times ="<<num_freq << std::endl;
//    }
//    else {
//        num_freq = 0;
//    }
//        previuos = currentk;
//    }
//    return 1;
//}
