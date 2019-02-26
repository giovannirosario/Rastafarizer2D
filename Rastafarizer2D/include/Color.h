#ifndef _COLOR_H_
#define _COLOR_H_

class Color {
    private:
        unsigned char rgb[3];

    public:
        Color();
        Color(unsigned char red, unsigned char green, unsigned char blue);
        void set(unsigned char red, unsigned char green, unsigned char blue);
        ~Color();
        
};  

#endif