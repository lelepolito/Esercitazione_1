#include <ostream>
#include <concepts>
#include <iostream>
#include <type_traits>

template<typename F>
concept FoD = std::is_floating_point_v<F>;
//concept FoD = std::is_same_v<F, float> || std::is_same_v<F, double>;
//Questo metodo fa in modo da creare un concetto che accetta solo float e double ,
//che esclude quindi long double rispetto a quello sopra.


template<typename F> requires FoD<F>
class c_num { 
private :
    F   p_r;
    F   p_i;
public :
    c_num(){
        p_r = 0 ;
        p_i = 0 ;
    }
    c_num(F r,F i){
        p_r = r ;
        p_i = i ;
    }
    c_num coniugate(){
        p_i = -p_i;
        return c_num(p_r, p_i);
    }
    F real(){
        return(p_r);
    }    
    F imm(){
        return(p_i);
    }
    c_num   operator*(c_num const& num2){
        c_num out ;
        out.p_i = p_r * num2.p_i + num2.p_r * p_i;    
        out.p_r = p_r * num2.p_r - p_i * num2.p_i;
        return out;
    }
    c_num operator+(c_num const& num2){
        c_num out;
        out.p_i = p_i + num2.p_i;
        out.p_r = p_r + num2.p_r;
        return out;
    }
    void operator+=(c_num const& num2){
        p_i = p_i + num2.p_i;
        p_r = p_r + num2.p_r;
    }
    void operator*=(c_num const& num2){
        p_i = p_r * num2.p_i + num2.p_r * p_i;    
        p_r = p_r * num2.p_r - p_i * num2.p_i;   
    }
    void operator+=(F num2){
        p_r = p_r + num2;
    }
    c_num operator+(F const& num2){
        c_num out;
        out.p_i = p_i;
        out.p_r = p_r + num2;
        return out;
    }
    template<typename T> requires FoD<T>
    friend std::ostream& operator<<(std::ostream& os,const c_num<T>& num);
    
    template<typename T> requires FoD<T>
    friend c_num<T> operator+(T const& num2,c_num<T> const& num1);
    
    template<typename T> requires FoD<T>
    friend c_num<T> operator*(T const& num2,c_num<T> const& num1);
    
    template<typename T> requires FoD<T>
    friend c_num<T> operator*(c_num<T> const& num1,T const& num2);
};




template<typename F> requires FoD<F>
std::ostream& operator<<(std::ostream& os,const c_num<F>& num) {
    if (num.p_i < 0)
        os << num.p_r << num.p_i<< "i";
    else if(num.p_i == 0)
        os << num.p_r;   
    else 
        os << num.p_r << "+" << num.p_i<< "i";
    return os;
};


template<typename F> requires FoD<F>
c_num<F> operator+(F const& num2,c_num<F> const& num1){
    c_num<F> out;
    out.p_i = num1.p_i;
    out.p_r = num1.p_r + num2;
    return out;
}


template<typename F> requires FoD<F>
c_num<F> operator*(c_num<F> const& num1,F const& num2){
    c_num<F> out;
    out.p_i = num1.p_i * num2;
    out.p_r = num1.p_r * num2;
    return out;
}


template<typename F> requires FoD<F>
c_num<F> operator*(F const& num2,c_num<F> const& num1){
    c_num<F> out;
    out.p_i = num1.p_i * num2;
    out.p_r = num1.p_r * num2;
    return out;
}




int main(){
    std::cout << "Alcuni test per provare il codice" << std::endl;
    c_num<float> f(2536.3435,-376.3623);
    c_num<float> f2(4352.41245,1415.3253);
    c_num<float> f3 = f + f2;
    c_num<double> f5(2536.3435,-376.3623);
    c_num<float> f9;
    c_num<float> f6= f.coniugate();
    c_num<float> f4 = f * f2;
    c_num<double> f10 = double(5.0) * f5;
    c_num<float> f11 = f * 50.0f;
    c_num<float> f12 = 50.0f + f;
    float f8= f.imm();
    float f7= f.real();
    std::cout << f5 << std::endl;
    std::cout << f3 << std::endl;
    std::cout << f4 << std::endl;
    std::cout << f << std::endl; 
    std::cout << f6 << std::endl;
    std::cout << f7 << std::endl;
    f9 = f + 5.0f;
    std::cout << f12<< std::endl;    
    std::cout << f9 << std::endl;  
 

    std::cout << f8 << std::endl;
    std::cout << f10 << std::endl;
    std::cout << f11 << std::endl;

    f += f2;
    std::cout << f << std::endl;
    f *= f2;
    std::cout << f << std::endl;
    return 0;
};
