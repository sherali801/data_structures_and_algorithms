#ifndef SEARCHING_SORTING_H_
#define SEARCHING_SORTING_H_

int bubbleSort(float arr[], int N) {
  int count = 0;
  bool swaped = false;
  do {
    swaped = false;
    int i = 0;
    while (i < N - 1) {
      count++;
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swaped = true;
      }
      i++;
    }
  } while (swaped);
  return count;
}

int bubbleSort(int arr[], int N) {
  int count = 0;
  bool swaped = false;
  do {
    swaped = false;
    int i = 0;
    while (i < N - 1) {
      count++;
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swaped = true;
      }
      i++;
    }
  } while (swaped);
  return count;
}

void merge(float arr[], int start, int mid, int end) {
  int leftSize = mid - start + 1;
  int rightSize = end - mid;
  float * left = new float[leftSize];
  float * right = new float[rightSize];
  int i = 0, j = 0, k = 0;
  for (i = 0, k = start; i < leftSize; i++, k++) {
    left[i] = arr[k];
  }
  for (j = 0, k = mid + 1; j < rightSize; j++, k++) {
    right[j] = arr[k];
  }
  i = 0;
  j = 0;
  k = start;
  while (i < leftSize && j < rightSize) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < leftSize) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < rightSize) {
    arr[k] = right[j];
    j++;
    k++;
  }
  delete left;
  delete right;
}

void mergeSort(float arr[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void merge(int arr[], int start, int mid, int end) {
  int leftSize = mid - start + 1;
  int rightSize = end - mid;
  int * left = new int[leftSize];
  int * right = new int[rightSize];
  int i = 0, j = 0, k = 0;
  for (i = 0, k = start; i < leftSize; i++, k++) {
    left[i] = arr[k];
  }
  for (j = 0, k = mid + 1; j < rightSize; j++, k++) {
    right[j] = arr[k];
  }
  i = 0;
  j = 0;
  k = start;
  while (i < leftSize && j < rightSize) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < leftSize) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < rightSize) {
    arr[k] = right[j];
    j++;
    k++;
  }
  delete left;
  delete right;
}

void mergeSort(int arr[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

int linearSearch(float arr[], int size, float key) {
  int count = 0;
  for (int i = 0; i < size - 1; i++) {
    count++;
    if (arr[i] == key) {
      return count;
    }
  }
  return count;
}

int linearSearch(int arr[], int size, int key) {
  int count = 0;
  for (int i = 0; i < size - 1; i++) {
    count++;
    if (arr[i] == key) {
      return count;
    }
  }
  return count;
}

int binarySearch(float * arr, int size, float key) {
  int count = 0;
  int start = 0;
  int end = size - 1;
  int mid;
  bool found = false;
  while (!found && start <= end) {
    count++;
    mid = (start + end) / 2;
    if (key == *(arr + mid)) {
      found = true;
    } else if (key < *(arr + mid)) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return count;
}

int binarySearch(int * arr, int size, int key) {
  int count = 0;
  int start = 0;
  int end = size - 1;
  int mid;
  bool found = false;
  while (!found && start <= end) {
    count++;
    mid = (start + end) / 2;
    if (key == *(arr + mid)) {
      found = true;
    } else if (key < *(arr + mid)) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return count;
}

#endif // !SEARCHING_SORTING_H_
