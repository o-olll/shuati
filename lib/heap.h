#include <vector>
#include <string>
#include <sstream>

namespace std
{
    template <class T>
    class MaxHeap {
    public:
        template <class ForwardIt>
        MaxHeap(ForwardIt from, ForwardIt to): _container(from, to) {
            build_heap();
        }

        void insert(const T&);

        inline string to_string() {
            ostringstream oss;
            for (T& v : _container) {
                oss << v << " ";
            }
            return oss.str();
        }

    private:
        vector<T> _container;

        void build_heap();
        void heapify(size_t);
        void heapify_up(size_t);

        inline size_t parent(size_t i) {
            return (i-1)/2;
        }

        inline size_t left(size_t i) {
            return i * 2 + 1;
        }

        inline size_t right(size_t i) {
            return i * 2 + 2;
        }

        inline size_t last_non_leaf() {
            return _container.size()/2 - 1;
        }
    };

    template<class T>
    void MaxHeap<T>::build_heap() {
        for (int i=last_non_leaf(); i>=0; --i) {
            heapify(i);
            /* for (int v : _container) */
            /*     printf("%d ", v); */
            /* printf("\n"); */
        }
    }


    template<class T>
    void MaxHeap<T>::heapify(size_t i) {
        size_t l, r, largest;
        T temp;

        l = left(i);
        r = right(i);
        temp = _container[i];
        largest = i;
        /*
        // if need to move value up
        while (i != 0 && temp > _container[parent(i)]) {
            _container[i] = _container[parent(i)];
            i = parent(i);
        }
        */
        // if need to move value down
        while (i <= last_non_leaf()) {
            if (left(i) < _container.size() &&
                temp < _container[left(i)]) {
                largest = left(i);
            }

            if (right(i) < _container.size() &&
                _container[largest] < _container[right(i)]) {
                largest = right(i);
            }

            if (i == largest){
                break;
            }

            _container[i] = _container[largest];
            i = largest;
        }
        _container[i] = temp;

        return;
    }

    template<class T>
    void MaxHeap<T>::heapify_up(size_t i) {
        T temp = _container[i];
        while (i != 0 && temp > _container[parent(i)]) {
            _container[i] = _container[parent(i)];
            i = parent(i);
        }
        _container[i] = temp;
    }

    template<class T>
    void MaxHeap<T>::insert(const T& v) {
        _container.push_back(v);
        heapify_up(_container.size()-1);
    }
}
