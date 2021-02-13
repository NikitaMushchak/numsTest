#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <bitset>
#include <future>
#include <thread>
#include <queue>
#include <atomic>
#include <random>
#include <complex>

#include <algorithm>


#define console(){char e; std::cout<<"Please enter char...";std::cin>>e;}
typedef  std::vector<int> vint;


bool isPrime(const int number) {
    if (number <= 1) {
        return false;
    }
    double num_double = (double)number;
    double max_number = sqrt(num_double);
    int max_int = int(max_number);
    for (int i = 2; i <= max_int; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

vint primesToArray(const int N) {
    vint array;
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            array.push_back(i);
        }
    }
    return array;
}
vint primesToArrayEratosfen(const int N) {
    std::vector<bool> sieve(sqrt(N));
    vint primes;

    for (int i = 2; i <= N; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j+=i) {
                sieve[j] = 1;
            }
        
        }
    }
    return primes;
}

bool ftask(int taskID) {
    static std::mutex task;
    task.lock();

    std::cout << "thread id : " << std::this_thread::get_id() << " task : " << taskID << std::endl;

    task.unlock();

    size_t sleep = std::rand() % 1000;
    std::this_thread::sleep_for(std::chrono::microseconds(sleep));
    return true;
}

class Item {
public:
    void start() {
        std::cout << "start():" << std::endl;
        std::cout << "thread id : " << std::this_thread::get_id() << std::endl;
    }
};


struct ListNode {


    int val;
    int size = 0;
    ListNode* head;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    void Push_Back(int number) {

        if (head == nullptr) {
            head = new ListNode(number);

        }
        else {
            ListNode* current = this->head;
            if (current->next != nullptr) {
                current = current->next;
            }
            current->next = new ListNode(number);
        }
        size++;
    }
};

void task1102() {
    std::vector<double > vec(2);
    std::vector<std::string> dim(2);
    std::cout << "Enter int 2 numbs with dimentions:" << std::endl;
    int i = 0;
    double multipl = 0;
    while (i<2) {
        std::cin >> vec[i]>> dim[i];
        std::cout << "You enter : " << vec[i]<<" "<<dim[i]<<std::endl;
        if (dim[i] == "galons" || dim[i] == "km" || dim[i] == "gallons")
            std::cout<<"Wrong dimention";

        if (dim[i] == "m") { 
            vec[i] *= 1000;
            
        }
        if (dim[i] == "ft") {
            vec[i] *= 12;
            dim[i] = "in";
        }
        if (dim[i] == "in") {
            vec[i] *= 2.54;
            
        }
        
        dim[i] = "cm";
        i++;
    }

    std::sort(vec.begin(), vec.end());

    std::cout << "min= " << vec[0] << std::endl;
    if (vec[0] == vec[1])
        std::cout << "Number equals!" << std::endl;

    if (abs(vec[0] - vec[1]) < (1.0 / 100))
        std::cout << "Number is close!" << std::endl;
    
    console();
}

void upr11_02() {
    std::vector<double> v;
    for (int i = 0; i < 12; ++i)
        v.push_back(i);

    double median = 0.;

    for (auto a : v)
        median += a;

    median /= v.size();

    std::cout << "median : " << median << std::endl;
    std::sort(v.begin(), v.end());
    std::cout << "min = " << v[0] << " max = " << v[v.size() - 1] << std::endl;
    std::cout << "(&v+2) : " << &v << std::endl;
    console();
}

int guessNum() {
    std::cout << "Enter num from 1 to 100" << std::endl;
    int a;
    std::cin >> a;
    int guess = 100/2;
    
    int step = guess / 2;

    for (int i = 0; i < 7; i++) {
        char choice;
        std::cout << ">=" << guess << "?" << std::endl;
        std::cout << "Y or N" << std::endl;
        std::cin >> choice;
        if (choice == 'Y') {
            guess = guess + step;
        }
        else {
            guess = guess - step;
        }
        step /=2;
        
        if (step < 1) step = 1;
    }
    /*std::cerr << "Your num = " << guess;
    console();*/

    return guess;
}

void simplecalc() {
    std::cout << "Simple calculator:" << std::endl;

    std::string znak;
    double a;
    double b;
    std::cout << "Enter like + 6 5" << std::endl;
    std::cin >> znak >> a >> b;

    if (znak == "+") {
        std::cout << "Summ of " << a << " and " << b << " is " << a + b << std::endl;
    }

    if (znak == "-") {
        std::cout << "Diff of " << a << " and " << b << " is " << a - b << std::endl;
    }
    if (znak == "*") {
        std::cout << "Multiplication of " << a << " and " << b << " is " << a * b << std::endl;
    }

    if (znak == "/") {
        std::cout << "Division of " << a << " and " << b << " is " << a / b << std::endl;
    }
    console();
}

void outputnumber() {
    std::vector<std::string> collection = { "zero","one","two","three","four","five",
                                            "six","seven","eigth","nine" };
    int it;
    std::cout<< "Please enter num from 0 to 9" << std::endl;
    std::cin>> it;
    std::cout << "it is = " << collection[it] << std::endl;

    console();
}

int numcells(int& numrice) {
    
    return (numrice / 2);
}

void numcellf(int numrice) {
    int i;
    for (i = 0; numrice > 1; i++) {
        numrice = numcells(numrice);
        //std::cout << "numrice " << numrice << std::endl;
    }

    std::cout << "numof celles = " << i << std::endl;
}

double numcellsdouble(double& numrice) {

    return (numrice / 2);
}

void numcelldouble(double numrice) {
    double i;
    for (i = 0; numrice > 1; i++) {
        numrice = numcellsdouble(numrice);
        //std::cout << "numrice " << numrice << std::endl;
    }

    std::cout << "numof celles = " << i << std::endl;
}

void rockPaperScissors(void) {
    int byte=-1;
    int predict = 0;
    do {
        std::cout << "Please enter 1 to Rock, 2 to Paper and 3 to Scissors" << std::endl;
        
        std::cin >> byte;
        switch (byte)
        {
        case 1:
            std::cout << " You type the Rock" << std::endl;
            break;
        case 2:
            std::cout << "You enter the Paper" << std::endl;
            break;
        case 3:
            std::cout << "You enter the Scissors" << std::endl;
            break;
        default:
            std::cout << "Wrong type! Please type again";
            continue;
            break;
        }

        predict = rand() % 3 + 1;

        std::cout << "Computer rand : " << predict << std::endl;
        switch (predict)
        {
        case 1:
            std::cout << "Comp the Rock" << std::endl;
            break;
        case 2:
            std::cout << "Comp the Paper" << std::endl;
            break;
        case 3:
            std::cout << "Comp the Scissors" << std::endl;
            break;
        default:
            std::cout << "Stupud computer!";
            continue;
            break;
        }
       /* if (byte == 1) {
            switch (predict)
            {
            case 3:
                std::cout << "You Win!" << std::endl;
                break;
            case 2:
                std::cout << "You loose" << std::endl;
                break;
            default:
                std::cout << "Another round!" << std::endl;
                break;
            }
        }
        if (byte == 2) {
            switch (predict)
            {
            case 3:
                std::cout << "You loose!" << std::endl;
                break;
            case 1:
                std::cout << "You Win" << std::endl;
                break;
            default:
                std::cout << "Another round!" << std::endl;
                break;
            }
        }
        if (byte == 3) {
            switch (predict)
            {
            case 2:
                std::cout << "You Win!" << std::endl;
                break;
            case 1:
                std::cout << "You loose" << std::endl;
                break;
            default:
                std::cout << "Another round!" << std::endl;
                break;
            }
        }*/
        int res = byte - predict;
        if (abs(res) > 1)
            res *= -1;
        
        if (res > 0)
            std::cout << "You win!" << std::endl;
        else
            if (res == 0)
                std::cout << "Anothe round!" << std::endl;
            else
                std::cout << "You loose!" << std::endl;
    } while (byte == predict);
}

bool isprime(int number) {
    if (number < 2)
        return false;

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
//
bool isprimrerastofen(int N) {
    std::vector<bool> net(N, true);
    for (int i = 2; (i * i) < N; ++i) {
        for (int j = i * i; j < N; j += i) {
            net[j] = false;
        }
    }

    std::cout << "prime numbers from 2 to " << N << std::endl;

    for (int i = 2; i < net.size();++i) {
        if (net[i])
            std::cout << i << std::endl;
    }
    return true;
}

void primenumbers(void) {
    std::vector<int> primes;

    std::cout << "Please enter the number:" << std::endl;

    int max;
    std::cin >> max;

    for (int i = 0; i < max; ++i) {
        if (isprime(i)) {
            primes.push_back(i);
        }
    }

    std::cout << "Prime numbers from 1 to "<<max<<" : "<< std::endl;
    for (int num : primes)
        std::cout << "prime num : " << num << std::endl;
}

void nprimenumbers(int N) {
    std::vector<int> primes;

    for (int i = 0; i < N*N; ++i) {
        if (isprime(i)) {
            primes.push_back(i);
            if (primes.size() == N)
                break;
        }
    }

    std::cout << N<<" Prime numbers" << std::endl;
    for (int num : primes)
        std::cout << "prime num : " << num << std::endl;
}
void modenum() {
    std::vector<int> vec{0,1,2,3,4,5,6,222,3,3,74,2,5,2, 3};

    std::sort(vec.begin(), vec.end());

    int times = 0;
    int maxtimes = 0;
    int mode = 0;
    for (int it = 0; it < vec.size()-1; ++it) {
        if (vec[it] == vec[it + 1]) {
            times++;
            if (maxtimes < times) {
                maxtimes = times;
                mode = vec[it];
            }
        }
        else {
            times = 0;
        }
        
    }
    std::cout << "mode = " << mode << std::endl;
}
void nodestring() {
    std::vector<std::string> vec = { "assap","a","b","fssd","s","a","zzet" };
    std::sort(vec.begin(), vec.end());

    int times = 0;
    int maxtimes = 0;
    std::string mode;
    for (int it = 0; it < vec.size() - 1; ++it) {
        if (vec[it] == vec[it + 1]) {
            times++;
            if (maxtimes < times) {
                maxtimes = times;
                mode = vec[it];
            }
        }
        else {
            times = 0;
        }

    }
    std::cout << "mode = " << mode << std::endl;

    std::cout << "min = " << vec.front() << " max = " << vec.back() << std::endl;
}

void quadraticeq() {
    double a;
    double b;
    double c;

    std::cout << "Enter cooefs of eq ax^2+bx+c = 0 like a b c" << std::endl;
    std::cin >> a >> b >> c;

    std::complex<double> x1;
    std::complex<double> x2;

    x1 = (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a);
    x2 = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);


    std::cout << "Roots : " << x1 << " , " << x2 << std::endl;
}

void pair() {
    std::vector <std::string> names;
    std::vector<int> scores;
    std::string name;
    int score;
    std::cout << "Type Name score" << std::endl;
    do{
        std::cin >>name>>score;
        if(name != "NoName")
            names.push_back(name);
        if(score !=  0)
            scores.push_back(score);
    } while (name != "NoName" && score != 0);

    for (int i = 0; i < scores.size(); ++i) {
        std::cout << " Name : " << names[i] << ", score = " << scores[i] << std::endl;
        for (int j = i + 1; j < scores.size(); ++j) {
            if (names[i] == names[j]) {
                std::cout << "Name : " << names[i] << " append multiple times!" << std::endl;
                names.erase(names.begin() + j);
                scores.erase(scores.begin() + j);
                --j;
            }
        }
    }
    std::cout << "Please enter the score:" << std::endl;

    int sc;
    std::cin >> sc;
    std::vector<std::string> scorename;
    for (int it = 0; it < scores.size(); ++it) {
        if (scores[it] == sc) {
            scorename.push_back(names[it]);
        }
    }

    std::cout << "Peaople with entered score:" << std::endl;
    for (auto g : scorename)
        std::cout << g<<std::endl;
}