#include "../system/system_methods.ipp"
#include "__service.ipp"

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

template <typename T>
std::vector<int> insert_test_3(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    g_start1 = timer();
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    g_end1 = timer();
    v.push_back(vector[3]);
    v.push_back(vector.size());
    //debug
    // std::cout<<"(unit-test::insert::range) v.capacity()"<<vector.capacity()<<std::endl;
    //end debug
    v.push_back(vector.capacity());

    B* k2(new B(3));
    B* k3(new B(4));
    B* k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    //debug
    delete k2;
    delete k3;
    delete k4;
    // std::cout<<"(unit-test::insert::range) v1.size()"<<v1.size()<<std::endl;
    //end debug

    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {

        v.push_back(vv.size());
        v.push_back(vv.capacity());
    //debug
    // std::cout<<"(unit-test::insert::range) v.size == "<<v.size()<<std::endl;
    //end debug
    }

    return v;
}

template <typename T>
std::vector<int> insert_test_3(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    g_start2 = timer();
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    g_end2 = timer();
    v.push_back(vector[3]);
    v.push_back(vector.size());
    //debug
    // std::cout<<"(unit-test::insert::range) _v.capacity()"<<vector.capacity()<<std::endl;
    //end debug

    v.push_back(vector.capacity());

    B* k2(new B(3));
    B* k3(new B(4));
    B* k4(new B(-1));
    _vector<A> vv;
    _vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    //debug
    delete k2;
    delete k3;
    delete k4;

    // std::cout<<"(unit-test::insert::range) _v1.size()"<<v1.size()<<std::endl;
    //end debug
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {

        v.push_back(vv.size());
        v.push_back(vv.capacity());
            //debug
    // std::cout<<"(unit-test::insert::range) _v.size == "<<v.size()<<std::endl;
    //end debug
    }

    return v;
}

int main() {

    exit(run_vector_unit_test<int>("insert(range)", insert_test_3, insert_test_3));
}