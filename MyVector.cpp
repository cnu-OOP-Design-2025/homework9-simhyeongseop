#include <iostream>
#include <string>
#include <list>
#include <stdexcept>
using namespace std;

template<typename T>
class MyVector {
    /* TODO */
private:
    T* data;
    size_t capacity;
    size_t length;

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;
        
        // capacity의 크기를 2배로 늘리고
        size_t newCapacity = capacity * 2;
         
        // 새로운 배열을 생성하세요.
        T* newData = new T[newCapacity];
        
        // 기존 데이터를 새로운 배열로 복사한 뒤,
        for (size_t i = 0; i < length; ++i){
            newData[i] = data[i];
        }
        
        // 기존 배열을 해제하세요.
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    MyVector() : capacity(2), length(0) {
        /* TODO */
        // data는 capacity 크기의 배열을 동적 할당하세요.
        data = new T[capacity];
    }

    ~MyVector() {
        /* TODO */
        // 동적 할당된 data를 해제하세요.
        delete[] data;
    }

    void push_back(const T& value) {
        /* TODO */
        // length가 capacity에 도달하면 resize()를 호출하세요.
        if (length == capacity){
            resize();
        }

        /* TODO */
        // 새로운 요소를 배열 끝에 추가하고 length를 증가시키세요.
        data[length] = value;
        length += 1;
    }

    // 마지막 항목을 리턴하세요.
    T pop_back() {
        if (length == 0){
            throw out_of_range("Vector is empty");
        }
        return data[--length];
    }

    // 주어진 index의 요소를 반환하세요.
    T& operator[](const int index) {
        return data[index];
    }

    // 현재 저장된 요소 개수를 반환하세요.
    size_t size() const {
        return length;
    }

    T* begin() { return data; }
    T* end() { return data + length; }
    const T* begin() const { return data; }
    const T* end() const { return data + length; }
};

template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (auto& e : vec)
        cout << e << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}
