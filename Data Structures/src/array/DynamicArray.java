package array;

import java.util.Iterator;

public class DynamicArray<T> implements Iterable<T> {

    // using a static array internally
    private T[] arr;
    // length of the array user thinks
    private int len = 0;
    // actual length of the array
    private int capacity = 0;

    public DynamicArray() {
        this(16);
    }

    /**
     * Initialises the array with given initial capacity
     */
    public DynamicArray(int capacity) {
        if(capacity < 0) {
            throw new IllegalArgumentException("size of array can't be less than zero");
        }
        this.capacity = capacity;
        arr = (T[]) new Object[capacity];
    }

    /**
     * returns the current size of the array
     */
    public int size() {
        return len;
    }

    /**
     * checks if the array is empty or not
     */
    public boolean isEmpty() {
        return size() == 0;
    }

    /**
     * return the element present at given index
     */
    public T get(int index) {
        // bounds checking
        if(index >= size() || index < 0) {
            throw new IndexOutOfBoundsException();
        }
        return arr[index];
    }

    /**
     * update element at given index
     */
    public void set(int index, T ele) {
        // bounds checking
        if(index >= size() || index < 0) {
            throw new IndexOutOfBoundsException();
        }
        arr[index] = ele;
    }

    /**
     * clear the array
     */
    public void clear() {
        for(int i = 0; i < size(); i++) {
            arr[i] = null;
        }
        len = 0;
    }

    /**
     * adds a new element to the array
     */
    public void add(T ele) {
        // array maximum capacity reached, time to resize
        if(len + 1 >= capacity) {
            // double the capacity of array
            if(capacity == 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }
            T[] newArr = (T[]) new Object[capacity];
            // copy old array elements into new array
            System.arraycopy(arr, 0, newArr, 0, len);
            arr = newArr;
        }
        arr[len] = ele;
        len++;
    }

    /**
     * removes and returns element from the given index
     */
    public T removeAt(int index) {
        if(index >= len || index < 0) {
            throw new IndexOutOfBoundsException();
        }
        T temp = arr[index];
        // allocate a new array of size one less than original size
        T[] tempArr = (T[]) new Object[len - 1];
        int i = 0, j = 0;
        // copy elements into new array
        while(i < len) {
            // check if current index is the index to be skipped
            if(i == index) {
                j--;
            }
            else {
                tempArr[j] = arr[i];
            }
            i++;
            j++;
        }
        // update array and size
        arr = tempArr;
        len--;
        capacity = len;
        return temp;
    }

    /**
     * remove first occurrence of given element from the array
     */
    public boolean remove(T ele) {
        int index = indexOf(ele);
        if(index == -1) {
            return false;
        }
        removeAt(index);
        return true;
    }

    /**
     * return the index of given element in given array
     */
    public int indexOf(T ele) {
        for(int i = 0; i < size(); i++) {
            if((arr[i] == null && ele == null) || ele.equals(arr[i])) {
                return i;
            }
        }
        // element not found
        return -1;
    }

    /**
     * checks if the array contains given element
     */
    public boolean contains(T ele) {
        return indexOf(ele) != -1;
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<>() {

            int index = 0;

            @Override
            public boolean hasNext() {
                return index < size();
            }

            @Override
            public T next() {
                T temp = arr[index];
                index++;
                return temp;
            }
        };
    }
}
