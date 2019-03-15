#include "ScanlineFill.h"
#include "Point2D.h"
#include <algorithm>
#include <utility>
#include <iostream>

ScanlineFill::ScanlineFill(Canvas& canvas, std::vector<Point2D> points, Color color) {
    this->points = points;
    this->canvas = &canvas;
    this->color = color;

    initEdges();
    bool anti_aliasing = this->canvas->is_antiAliasing();
    this->canvas->set_antiAliasing(false);
    fill();
    this->canvas->set_antiAliasing(anti_aliasing);
}

ScanlineFill::~ScanlineFill() {}

bool compare_yMin(const Edge &a, const Edge &b) {
    return a.y_min < b.y_min;
}

bool compare_x(const Edge &a, const Edge &b) {
    return a.x < b.x;
}

void ScanlineFill::initEdges() {
    for(unsigned int i = 0; i < points.size(); i++){
        Edge edge;
        int x1,x2,y1,y2;
        if (i == points.size()-1) {
           y1 = points[0].get_y();
           y2 = points.back().get_y();
           x1 = points[0].get_x();
           x2 = points.back().get_x();
        } else {
           y1 = points[i].get_y();
           y2 = points[i+1].get_y();
           x1 = points[i].get_x();
           x2 = points[i+1].get_x();
        }

        if(y2 < y1) {
            std::swap(x1,x2);
            std::swap(y1,y2);
        }
            
        edge.y_max = y2;
        edge.y_min = y1;
        edge.x = x1;
        edge.d_x = x2 - x1;
        edge.d_y = y2 - y1;

        edges.push_back(edge);
    }

    std::sort(edges.begin(), edges.end(), compare_yMin);
}

void ScanlineFill::fill() {
    int y_pos = edges.front().y_min;;
    while (!edges.empty() || !active_list.empty()) {
        //Move from ET to AET 
        for(int i = 0; i < edges.size();) {
            if (edges[i].y_min == y_pos) {
                active_list.push_back(edges[i]);
                edges.erase(edges.begin()+i);
            } else {
                i++;
            }
       }

        std::sort(active_list.begin(), active_list.end(), compare_x);
        

        for(int i = 0; i < active_list.size();) {
            if (active_list[i].y_max == y_pos) {
                active_list.erase(active_list.begin() + i);
            } else {
                i++;
            }
        }
        
        //Fill pixels
        for(int i = 0; i < active_list.size(); i = i+2) {
            int x1 = active_list[i].x;
            int x2 = active_list[i+1].x;

            for(int i = x1; i < x2; i++) {
                canvas->draw_pixel(i,y_pos,color);
            }   
        }

        y_pos++;
            
        for(int i = 0; i < active_list.size(); i++) {
            if(active_list[i].d_y != 0) {
                active_list[i].x += ((double) active_list[i].d_x/active_list[i].d_y);
            }
        }
    }
}