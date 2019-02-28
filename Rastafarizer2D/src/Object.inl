#include "Object.h"

template <class T>
void Object<T>::Object(T object) {
    this.object = object;
}

template <class T>
void Object<T>::~Object(T object) {}

template <class T>
void Object<T>::draw() {
    return this.object.draw();
}