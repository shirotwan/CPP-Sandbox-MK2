#pragma once
#include <Eigen/Eigenvalues>

namespace levelup{

    template<typename matrix_type> matrix_type apply_func_s(matrix_type matrix_target, typename Eigen::DenseBase<matrix_type>::Scalar func(typename Eigen::DenseBase<matrix_type>::Scalar)){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = func(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type exp_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::exp(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type log_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::log(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type sqrt_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::sqrt(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type pow_s(matrix_type matrix_target, typename Eigen::DenseBase<matrix_type>::Scalar val){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::pow(D_matrix(iterator_i,iterator_i), val);
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type mpow_s(matrix_type matrix_target1, matrix_type matrix_target2){
        return exp_s<matrix_type>(matrix_target2 * log_s(matrix_target1));
    }

    template<typename matrix_type> matrix_type cos_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::cos(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type sin_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::sin(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type tan_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::tan(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type acos_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::acos(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type asin_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::asin(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type atan_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::atan(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type cosh_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::cosh(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type sinh_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::sinh(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type tanh_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::tanh(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type acosh_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::acosh(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type asinh_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::asinh(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }

    template<typename matrix_type> matrix_type atanh_s(matrix_type matrix_target){
        Eigen::ComplexEigenSolver<matrix_type> solve_eig(matrix_target);
        int iterator_i = 0; int size_mat = matrix_target.rows(); 
        matrix_type D_matrix = matrix_type(solve_eig.eigenvalues().asDiagonal());
        matrix_type P_matrix = solve_eig.eigenvectors();

        for(; iterator_i != size_mat; iterator_i++){
            D_matrix(iterator_i,iterator_i) = std::atanh(D_matrix(iterator_i,iterator_i));
        }

        return P_matrix * D_matrix * P_matrix.inverse();
    }
}