#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #include <iostream>
    #define __IS_AN_OS__ 1
#elif __APPLE__
    #include <TargetConditionals.h>
    #include <iostream>
    #define __IS_AN_OS__ 1
#elif __linux__
    #include <iostream>
    #define __IS_AN_OS__ 1
#elif __unix__
    #include <iostream>
    #define __IS_AN_OS__ 1
#elif defined(_POSIX_VERSION)
    #include <iostream>
    #define __IS_AN_OS__ 1
#else
    #define __IS_AN_OS__ 0
#endif

#if UINTPTR_MAX == 0xffffffffffffffff || __x86_64__
    #include <cstdint>
    #define __16_BIT_CONFIG_ITERATOR__
#else
    #include <stdint.h>
#endif

#ifdef _OPENMP
    #include <omp.h>
#endif

#if defined(__8_BIT_CONFIG_ITERATOR__)
    typedef uint_fast8_t __INT_ITERATOR__;
#elif defined(__16_BIT_CONFIG_ITERATOR__)
    typedef uint_fast16_t __INT_ITERATOR__;
#elif defined(__32_BIT_CONFIG_ITERATOR__)
    typedef uint_fast32_t __INT_ITERATOR__;
#elif defined(__64_BIT_CONFIG_ITERATOR__)
    typedef uint_fast64_t __INT_ITERATOR__;
#else
    #warning "No bits or architecture selected! Switching automatically to 8 bit."
    typedef uint_fast8_t __INT_ITERATOR__;
#endif

__INT_ITERATOR__ __iterator_thread_one__ = 0, __iterator_thread_two__ = 0, __iterator_thread_three__ = 0;

namespace brain{
    template <class __VEC_TYPE__, __INT_ITERATOR__ __VEC_SIZE__> class Vec{
        __VEC_TYPE__ VecBuff[__VEC_SIZE__]; // Buffer data of the vector

        public:
        Vec(){for(__iterator_thread_one__ = 0; __iterator_thread_one__ != __VEC_SIZE__; __iterator_thread_one__++) VecBuff[__iterator_thread_one__] = 0;}
        Vec(__VEC_TYPE__* copy_vec){ memcpy(VecBuff,copy_vec,__VEC_SIZE__*sizeof(__VEC_TYPE__)); } // Main constructor

        // Element manipulation

        inline __VEC_TYPE__ get_element(__INT_ITERATOR__ pos_v){ return VecBuff[pos_v];}
        inline void set_element(__INT_ITERATOR__ pos_v, __VEC_TYPE__ value){ VecBuff[pos_v] = value; }

        // Print pn screen
        #if __IS_AN_OS__ == 1
        void v_out(){
            std::cout << "[ ";
            for(__VEC_TYPE__ e: VecBuff){std::cout << e << " ";}
            std::cout << "]";
        }

        template <class __VEC_TYPE__X__, __INT_ITERATOR__ __VEC_SIZE__X__> 
        friend std::ostream& operator<<(std::ostream& os, Vec<__VEC_TYPE__X__,__VEC_SIZE__X__> v);

        #endif
    };

    template <class __POLY_TYPE__, __INT_ITERATOR__ __POLY_SIZE__> class Poly{
        __POLY_TYPE__ PolyBuff[__POLY_SIZE__];
        #if __IS_AN_OS__ == 1
        char var_name[2] = "x";
        #endif

        public:
        Poly(){for(__iterator_thread_one__ = 0; __iterator_thread_one__ != __POLY_SIZE__; __iterator_thread_one__++) PolyBuff[__iterator_thread_one__] = 0;}
        Poly(__POLY_TYPE__* coeffs){memcpy(PolyBuff,coeffs,__POLY_SIZE__*sizeof(__POLY_TYPE__));}

        // Element manipulation

        inline __POLY_TYPE__ get_element(__INT_ITERATOR__ pos_v){ return PolyBuff[pos_v];}
        inline void set_element(__INT_ITERATOR__ pos_v, __POLY_TYPE__ value){ PolyBuff[pos_v] = value; }

        // Print on screen
        #if __IS_AN_OS__ == 1
        void p_out(){
            for(__iterator_thread_one__ = __POLY_SIZE__; __iterator_thread_one__ != 0; __iterator_thread_one__--){
                std::cout << PolyBuff[__iterator_thread_one__ - 1] << " * " << var_name << "^(" << (__iterator_thread_one__ - 1) << ")" << (__iterator_thread_one__ != 1 ? " + " : "" );
            }
        }

        template <class __POLY_TYPE__X__, __INT_ITERATOR__ __POLY_SIZE__X__> 
        friend std::ostream& operator<<(std::ostream& os, Poly<__POLY_TYPE__X__,__POLY_SIZE__X__> p);

        #endif
    };

    template <class __MAT_TYPE__, __INT_ITERATOR__ __MAT_ROWS__, __INT_ITERATOR__ __MAT_COLS__> class Mat{
        __MAT_TYPE__ MatBuff[__MAT_ROWS__ * __MAT_COLS__];

        public:
        Mat(__MAT_TYPE__* copy_straight_mat){ memcpy(MatBuff, copy_straight_mat, __MAT_ROWS__*__MAT_COLS__*sizeof(__MAT_TYPE__) ); } // Constructor for strip arrays

        Mat(__MAT_TYPE__ copy_double_mat[__MAT_ROWS__][__MAT_COLS__]){ // Constructor for normal arrays
            for(__iterator_thread_one__ = 0; __iterator_thread_one__ != __MAT_ROWS__; __iterator_thread_one__++){
                for(__iterator_thread_two__ = 0; __iterator_thread_two__ != __MAT_COLS__; __iterator_thread_two__++){
                    MatBuff[ __iterator_thread_one__*__MAT_COLS__ + __iterator_thread_two__] = copy_double_mat[__iterator_thread_one__][__iterator_thread_two__];
                }
            }
        }

        // Element manipulation

        inline __MAT_TYPE__ get_element(__INT_ITERATOR__ pos_r, __INT_ITERATOR__ pos_c){ return MatBuff[(pos_c%__MAT_COLS__) + (pos_r%__MAT_ROWS__)*__MAT_COLS__]; }
        inline void set_element(__INT_ITERATOR__ pos_r, __INT_ITERATOR__ pos_c, __MAT_TYPE__ value){ MatBuff[(pos_c%__MAT_COLS__) + (pos_r%__MAT_ROWS__)*__MAT_COLS__] = value; }

        // Print on screen
        #if __IS_AN_OS__ == 1
        void m_out(){
            for(__iterator_thread_one__ = 0; __iterator_thread_one__ != __MAT_ROWS__; __iterator_thread_one__++){
                std::cout << "[ ";
                for(__iterator_thread_two__ = 0; __iterator_thread_two__ != __MAT_COLS__; __iterator_thread_two__++){
                    std::cout << MatBuff[__iterator_thread_two__ + __iterator_thread_one__*__MAT_COLS__] << " ";
                }
                std::cout << "]\n";
            }
        }
        #endif
    };

    // Operators

    #if __IS_AN_OS__ == 1
    template <class __VEC_TYPE__X__, __INT_ITERATOR__ __VEC_SIZE__X__>
    std::ostream& operator<<(std::ostream& os, Vec<__VEC_TYPE__X__,__VEC_SIZE__X__> v){
        os << "[ "; for(__VEC_TYPE__X__ e: v.VecBuff){std::cout << e << " ";} os << "]";
        return os;
    }
    template <class __POLY_TYPE__X__, __INT_ITERATOR__ __POLY_SIZE__X__> 
    std::ostream& operator<<(std::ostream& os, Poly<__POLY_TYPE__X__,__POLY_SIZE__X__> p){
        
    }
    #endif
}