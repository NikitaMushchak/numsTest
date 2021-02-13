#include "whattotest.cpp"
#include <bitset>


#include "gtest/gtest.h"
#include <future>
#include <stack>
//#pragma comment(lib,"pthreadVC3.lib")
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

TEST(ListNodetest, normtest) {

    ListNode* list1(0);

    ListNode** tlist1 = &list1;
    for (int i = 0; i < 10; ) {
        (*tlist1) = new ListNode(++i);
        tlist1 = &((*tlist1)->next);
    }

    //std::cout << "list1 = " << list1->val<<" ptr = "<<list1->next<<std::endl;
    ListNode** itlist = &list1;
    int iter = 0;
    while ((*itlist)->next != nullptr)
    {
        std::cout << "list element #" << iter << " : " << (*itlist)->val << std::endl;
        iter++;
        *itlist = (*itlist)->next;
    }
    // next
    std::cout << " buff pointer method :" << std::endl;
    int it = 0;
    ListNode** curr = &list1;
    while ((*curr)->next != nullptr)
    {
        std::cout << "curr #" << it++ << " = " << (*curr)->val << std::endl;
        *curr = (*curr)->next;

    }

    ListNode list(0);

    ListNode* pList = &list;

    for (int i = 0; i < 10;) {
        pList->next = new ListNode(++i);
        pList = pList->next;
    }
    int iterr = 0;
    ListNode* current = list.next;
    while (current->next != nullptr) {
        std::cout << "list member # " << iterr << " = " << current->val << std::endl;
        current = current->next;
        iterr++;
    }

}

TEST(task1102Tst, tee) {
    //task1102();
    //upr11_02();
   
}

int main(int argc, char **argv) {
    
    //outputnumber();
    numcellf(64);
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
