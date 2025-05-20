#ifndef SWEPT_VOLUME_FUN
#define SWEPT_VOLUME_FUN
#include <Eigen/Core>
#include <vector>

void swept_volume(const Eigen::MatrixXd & V, const Eigen::MatrixXi & F, const Eigen::MatrixXd & UV, const Eigen::MatrixXi & UVF, const std::string eps_str, const int num_seeds, const std::string dir_name, Eigen::MatrixXd & U, Eigen::MatrixXi & G);

void swept_volume(const Eigen::MatrixXd & V, const Eigen::MatrixXi & F, const std::string eps_str, const int num_seeds, const std::string dir_name, Eigen::MatrixXd & U, Eigen::MatrixXi & G);

#endif
