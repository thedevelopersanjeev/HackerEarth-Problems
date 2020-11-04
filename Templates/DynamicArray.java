public class DynamicArray<T> {

    private int capacity;
    private int currentSize;
    private T[] containerArray;

    public DynamicArray() {
        this(16);
    }

    @SuppressWarnings("unchecked")
    public DynamicArray(int initialCapacity) {
        this.capacity = initialCapacity;
        this.currentSize = 0;
        this.containerArray = (T[]) new Object[initialCapacity];
    }

    public T get(int index) {
        if (this.currentSize == 0 || index < 0 || index >= this.currentSize) {
            return null;
        } else {
            return this.containerArray[index];
        }
    }

    public void add(T element, int index) {
        if (this.currentSize == 0 || index < 0 || index >= this.currentSize) {
            return;
        }
        if (this.currentSize == this.capacity) {
            resizeContainerArray();
        }
        int lastIndex = this.currentSize - 1;
        while (lastIndex >= index) {
            this.containerArray[lastIndex + 1] = this.containerArray[lastIndex];
            lastIndex--;
        }
        this.currentSize++;
        this.containerArray[index] = element;
    }

    public void add(T element) {
        if (this.currentSize == this.capacity) {
            resizeContainerArray();
        }
        this.currentSize++;
        this.containerArray[currentSize - 1] = element;
    }

    public void remove(T element) {
        int index = getIndexOfElement(element);
        if (index != -1 && this.currentSize > 0) {
            while (index <= this.currentSize - 1) {
                this.containerArray[index] = this.containerArray[index + 1];
                index++;
            }
            this.currentSize = this.currentSize - 1;
        }
    }

    public void remove() {
        if (this.currentSize > 0) {
            this.containerArray[this.currentSize - 1] = null;
            this.currentSize = this.currentSize - 1;
        }
    }

    @SuppressWarnings("unchecked")
    private void resizeContainerArray() {
        T[] tempArray = (T[]) new Object[this.capacity * 2];
        for (int i = 0; i < this.capacity; i++) {
            tempArray[i] = this.containerArray[i];
        }
        this.containerArray = tempArray;
        this.capacity = this.capacity * 2;
    }

    public int getIndexOfElement(T element) {
        int answerIndex = -1;
        for (int i = 0; i < this.currentSize; i++) {
            if (this.containerArray[i] == element) {
                answerIndex = i;
                break;
            }
        }
        return answerIndex;
    }
}