#include "roots.hpp"
#include <cmath>

bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root) {
                double sign = f(a) * f(b);
                if (sign < 0) {
                    while(std::abs(b - a) > 1e-6) {
                        double c = (a + b)/2;
                        if (f(c) == 0) {
                            *root = c;
                            return true;
                        }
                        if (f(c) * f(a) < 0) {
                            b = c;
                        }
                        else if (f(c) * f(b) < 0) {
                            a = c;
                        }
                    }  
                    double c = (a + b)/2;
                    *root = c;
                }      
                else {return false;}
            return true;        
}
                

bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root) {
                    double sign = f(a) * f(b);
                    if (sign < 0) {
                        while(true) {
                            double c = a - ((f(a) * (b - a))/(f(b) - f(a)));
                            if (std::abs(f(c)) < 1e-6 || (b-a) < 1e-6) {
                                *root = c;
                                return true;
                            }
                            if (f(c) * f(a) < 0) {
                                b = c;
                            }
                            else if (f(c) * f(b) < 0) {
                                a = c;
                            }
                        }  
                    }      
                    else {return false;}
    return true;
}

bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root) {
                        while(true) {
                            double new_c = c - (f(c)/g(c));
                            if (std::abs(new_c - c) < 1e-6) {
                                *root = new_c;
                                return true;
                            }
                            c = new_c;
                        }
    return true;
}

bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root) {
                while(true) {
                    double new_value = b - f(b) * ((b-a)/(f(b) - f(a)));
                    if (std::abs(new_value - b) < 1e-6) {
                        *root = new_value;
                        return true;
                    }
                    a = b;
                    b = new_value;
                }

    return true;
}

