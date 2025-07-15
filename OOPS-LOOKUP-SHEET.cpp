// Author : Shivam Kapoor
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll mod7 = 1e9 + 7, mod9 = 998244353, INF = 1e18;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((ll)(v).size())
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rrep(i, a, b) for (ll i = (b)-1; i >= (a); --i)

#ifndef ONLINE_JUDGE
    #define debug(x) cout << "DEBUG: " << #x << " = " << (x) << endl;
    #define print(v) do { \
        cout << "vect--" << #v << " = [ "; \
        for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " "; \
        cout << "]\n"; \
    } while(0)
    #define print2d(v) do { \
        cout << "Matrix:\n"; \
        for (auto it = v.begin(); it != v.end(); ++it) { \
            for (auto jt = it->begin(); jt != it->end(); ++jt) cout << *jt << " "; \
            cout << "\n"; \
        } \
    } while(0)
    #define printmap(m) do { \
        cout << "Map:\n"; \
        for (auto it = m.begin(); it != m.end(); ++it) { \
            cout << it->first << " -> " << it->second << "\n"; \
        } \
    } while(0)
    #define printpp(v) do { \
        cout << "[ "; \
        for (auto it = v.begin(); it != v.end(); ++it) cout << "(" << it->first << ", " << it->second << ") "; \
        cout << "]\n"; \
    } while(0)
#else
    #define debug(x)
    #define print(v)
    #define print2d(v)
    #define printmap(m)
    #define printpp(v)
#endif

void myerase(ordered_set &t, int v) {
    auto it = t.find_by_order(t.order_of_key(v));
    if (it != t.end() && *it == v) t.erase(it);
}

ll modAdd(ll a, ll b, ll m = mod7) { return (a + b) % m; }
ll modSub(ll a, ll b, ll m = mod7) { return (a - b + m) % m; }
ll modMul(ll a, ll b, ll m = mod7) { return (a * b) % m; }
ll modExp(ll base, ll exp, ll m = mod7) { 
    ll res = 1; 
    while (exp) { 
        if (exp % 2) res = modMul(res, base, m); 
        base = modMul(base, base, m); 
        exp /= 2; 
    } 
    return res; 
}
ll modInv(ll a, ll m = mod7) { return modExp(a, m - 2, m); }

// Struct Usage
struct node {
    node* links[26];
    bool fg = false;

    node(){
        cout << "SCOPE STARTED" << endl;
        for(ll i = 0; i < 26; i++){
            links[i] = NULL;
        }
    }

    ~node(){
        cout << "GOES OUT OF SCOPE" << endl;
        for(ll i = 0; i < 26; i++){
            if(links[i]) links[i] = NULL;
        }
    }
};

// Basic Class Implementation
class Teacher {
    private:
        string name;
        ll salary;

    public: 
        Teacher(){
            name = "NOT DEFINED YET";
            salary = 0;
        }

        void setSalary(ll a){
            this -> salary = a;
        }
        void setName(string x){
            this -> name = x;
        }
        string getName(){
            return this -> name;
        }
        ll getSalary(){
            return this -> salary;
        }
};

// Encapsulation
// Wrapping up of Data members and other methods into a single unit called class is caled encapsulation
// Helps in data hiding
// By using access modifiers : 
// Private, Public, Protected
// Private: Access only inside the code or the friend class
// Public: Access everywhere even outside the class
// Protected: Acces ony to the derived and friend classes and not anywhere outside the code

// friend Classes and friend Functions
// these have even acces to the private members of the class
// the class grants permission to them and trust them

class A {
    private:
        ll val;
        // Syntac for a frined function
        friend void friendOfA(A a);
        // Syntax for a friend class
        friend class B;
    public:
        A(ll x){
            this -> val = x;
        }
};


// friend function
void friendOfA(A x){
    cout << x.val << endl;
}
// friend class 
class B {
    public:
    ll printAPrivateMember(A &x){
        cout << x.val << endl;
    }
};

// Using the protected keyword
class Animal {
    protected:
    string name;

    public:
        Animal(){
            cout << "CONSTRUCTOR OF ANIMAL CALLED" << endl;
        }
        setName(string a){
            name = a;
        }
};

class Dog : public Animal {
    public:
    Dog(){
        cout << "CONSTRUCTOR OF DOG CALLED" << endl;
    }
    // this Dog has the access to the setName of the parent and also the protected member name of the parent
    void speak(){
        cout << "WOOF! my nam is : " << name <<  endl;
    }
};

// Copy Constructor
// The default copy contructor by default makes a Shallow copy constructor  
// As in case of dynamic memory allcoation, when we copy using shallow copyit just copies the memory pointer and not
// the actual memory which it points to, as a result, if one memory delted the other object's pointer to that memory location becomes dangling
// and that pointer becomes a dangling pointer
// Example:

class C {
public:
    int* ax;
    C() {
        ax = new int(8);
    }
    C(C &y) {
        cout << "Custom Copy Constructor" << endl;
        ax = new int(*y.ax);  
    }
};

// Inheritance
// Multiple Inheritance
class papa {
    protected:
        ll value;
};

class mummy {
    protected:
        ll value1;
};

class bcha : public papa, public mummy {
    public:
        // but it is important that the value is protectd here also
        void bolo(){
            cout << "BETA ZARA KUCH TO BOLO: " << value << " " << value1 << endl; 
        }
        void setValue(ll x, ll y){
            value = x;
            value1 = y;
        }
};

// Diamond Problem
// and the use of virtual class
// what is the D inherits from B and C and B and C themselves inherits from A
// this creates a diamond problem because D is unaware that which A instance to choose ?
// for this we use virtual keyword
class AA {
public:
    void show() {
        cout << "A::show()" << endl;
    }
};

class BB : virtual public AA {};
class CC : virtual public AA {};
class DD : public BB, public CC {};


// Classic Example to show both function and operator overloading
class Complex {
public:
    ll r, i;

    Complex(){

    }
    Complex(ll x, ll y){
        r = x;
        i = y;
    }

    // Function Overloading
    void printi(string a){
        cout << "PRINTING STRING: " << a << endl; 
    }
    void printi(ll num){
        cout << "PRINTING NUMBER: " << num << endl;
    }

    // Operator overloading
    Complex operator + (Complex &other){
        return Complex(other.r + r, other.i + i);
    }
    Complex operator - (Complex &other){
        return Complex(-other.r + r, -other.i + i);
    }

    void printx(){
        cout << "REAL PART: " << r << endl;
        cout << "IMAGINARY PART: " << i << endl;
    }
};

// CLASSINC CASE OF VIRTUAL FUNCTIONS
// ALSO INFO ABOUT THE PURE INFO FUNCTIONS AND THE ABSTRACT CLASSES
class Alien {
    public:
        virtual void barks(){
            cout << "ALIEN BARKS!" << endl;
        }
        // Adding the below line would add a pure virtual function to this class
        // and thus it would not be possible to instantiate this class
        // This would make the Alien class as an abstract class
        // virtual void speaks();
};

class AlienKaBcha : public Alien {
    public: 
        void barks() override {
            cout << "BCHA BARKS" << endl;
        }
};

// This is an abstract class as it consists of >= 1 total pure virtual functions
class abstractClass {
    public: 
        virtual func1() = 0;
        virtual func2() = 0;
        virtual func3() = 0;
};

// static keyword in functions
void funco(){
    static int x = 1;
    cout << "x: " << x << endl;
    x++;
}

// static keyword in class
class ABC {
    public: 
    ll val;
    static int vali;
    ABC(){
        val = 10;
    }
    ~ABC(){
        cout << "DESTRUCTOR CALLED" << endl;
    }
};
// this has to be declared outside only (all static members infact in a class)
int ABC::vali = 5;

void solve() { 
    Teacher tc1;
    string str = tc1.getName();
    debug(str);
    tc1.setSalary(125000);
    tc1.setName("Shivam");

    string na = tc1.getName();
    debug(na);
    ll sal = tc1.getSalary();
    debug(sal);

    node* root = new node();
    delete root;

    cout << endl << "ENCAPSULATION UNDERSTANDING" << endl;
    A a(5);
    B b;
    b.printAPrivateMember(a);
    friendOfA(a);

    Dog dg;
    dg.setName("TOMMY");
    dg.speak();

    // yeh problem sirf dynamic memory usage mn hi aaegi kyuki static allocation mn hm proper nayi memory bnate h naaki
    // copy krte h pointers ko jo memory pr point krta h
    C c;
    C d = c;
    cout << *(d.ax) << endl;
    delete(d.ax);
    // Random buffer vaue at that location
    cout << *d.ax << endl;
    // but now the value of c is not changed for the d object the memory thas cleared was different to the memory which C pointed initially
    // So no change in C's memory pointer
    cout << *c.ax << endl;
    // So solution is allocation the memory value and not the poniter only
    // so make custom copy contructor

    // ONE MORE THING TO MAKE SURE IS THAT DESTRUCTOR ALWAYS IS RUN AUTOMATICALLY FOR STATICALLY ALLOCATED MEMORY
    // WHILE IT HAS TO BE RUN EXPLICITYY FOR DYNAMICALLY ALLOCATED MEMORY

    cout << endl;
    cout << "INHERITANCE UNDERSTADING" << endl; 
    bcha bc;
    bc.setValue(100, 200);
    bc.bolo();
    // DIAMOND PROBLEM
    DD dx;
    dx.show();
    cout << endl;
    cout << "POLYMORPHISM UNDERSTANDING" << endl;

    // Compiletime polymorphism -> Static Binding
    // Function Overloading
    Complex x;
    x.printi("HELLO");
    x.printi(69);
    // Operator Overloading
    Complex num1(4, 3);
    Complex num2(2, 5);
    Complex num3 = (num1 + num2);
    num3.printx();
    Complex num4 = (num1 - num2);
    num4.printx();
    // Runtime Polymorphism -> Dynamic Binding
    // Function overriding & Virtual Functions
    // Virtual Functions are those functions which can be written at a later stage in one its derives classes
    // The derived classes can change the behaviour of the parent classe's function
    Alien* al = new AlienKaBcha;
    // Ab dono br hi bcha barks print hoga kyuki Aient ka bcha aate hi base class ka bhi function over ride hogya h
    // agr nhi hona to virtual keyword hata do simply to nhi hoga override
    // NOTE: Virtual Functions allows derived class to override base behavior
    // Pure Virtual Functions : Those functions which do not have body of their own and are ony meant to be oveloaded
    // Abstract Classes : Classes which contain atleast 1 Pure Virtual functions is called as abstract class
    // such classes cannot be instantiated at all
    al -> barks();
    AlienKaBcha ab;
    al = &ab;
    al -> barks();

    cout << endl;
    cout << "UNDERSTANDING ABSTRACTION" << endl;
    // Data hiding and other important things to be exposed to other parts of the code for security and integrity issues
    // Abstract class : Blueprint for other classes to provide base class, in itself it cannot be implemented

    // The following abstract class cannot be instantiated
    // abstractClass ac;

    cout << "STATIC KEYWORD in VARIOUS CONTEXTS:" << endl;
    // STATIC KEYWORD:
    // in functions
    // ek br bngya to vhi rhega throughout the lifetime of the program
    // here x is only created once and modifed that x only everytime because it is static
    funco();
    funco();
    funco();
    // while const makes them unmodifyable throughout the program lifetime

    // in class
    // the static keyword is shared by all the objects created from that class
    cout << ABC::vali << endl;
    ABC::vali++;
    cout << ABC::vali << endl;

    // in objects
    // in context to objects these static keyword makes the object remain through out the lifeimte
    // example 
    if(1){
        ABC a1;
        // after going from the if the a1 would call its destructor because it now out of scope
    }
    cout << "KUCH HUA1" << endl;
    // but if i use th static keyword then it will not cause it to call destructor and will continue to exist in the program till the program lifetime finishes
    if(1){
        static ABC a2;
    }
    // still a2 is living
    cout << "KUCH HUA2" << endl;
    // ab dekho to ABC ka destructor call hoga tb jb pura program end hojaega (check in console)
}

int main() {
    fast_io
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
