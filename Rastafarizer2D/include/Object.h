#ifndef _OBJECT_H_
#define _OBJECT_H_

template <class T>

class Object {
    private:
        T object;
    public:
        Object();
        ~Object();
        void draw(Canvas canvas);
};

#endif