
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

//Thomas Tridiagonal Matrix Solver, Source: Applied Computational Physics by Joseph F. Boudreau, Eric S. Swanson
void triDiag(const double d,
             const double u,
             const double l,
             const std::vector <double> &r,
             std::vector <double> & x, const int offset) {
  std::vector <double> gamma (x);
  double beta = d;
  x[offset] = r[offset]/beta;
  for (int i=1+offset;i<x.size()-offset;i++) {
    gamma[i] = u/beta;
    beta = d - l*gamma[i];
    if (beta == 0.0) exit(0);
    x[i] = (r[i]-l*x[i-1])/beta;
  }
  for (int i=x.size()-2-offset;i>=offset;i--) 
    x[i] -= gamma[i+1]*x[i+1];
  return;
}

int main(int argc, char* argv[])
{
    double result;
    int nx = 80; // Number of position points Also Range of X
    int nt = 1000; // Number of time steps
    char buffer[100];
    double dt = 8.0/nt ;
    double dx = 10.0/nx;;

    // Intializing the boundry condition
    std::vector<std::vector<double>> T(nt+1, std::vector<double>(2*nx+1, 0.0)); 
    double sigma = 0.0; 
    std::vector<double> r(2*nx-1, 0.0); // Ax = r
    std::vector<double> u(2*nx-1, 0.0); // "A" upper diagonal vector 
    std::vector<double> l(2*nx-1, 0.0); // "A" lower diagonal vector
    std::vector<double> d(2*nx-1, 0.0); // "A" diagonal vector
    std::vector<double> x(2*nx-1, 0.0); // vector Xs
    sigma = dt/(2.0*dx*dx);
    std::cout << "dt = " << dt << ", " << "dx = " << dx << ", " <<"sigma = " << sigma << endl;
    
    for (int i = 0; i < 2*nx+1; i++)
    {
        if (std::strcmp(argv[1], "gaussian") == 0)
        {
            T[0][i] = pow ( 10.0 * i*dx - 4.0, 2 ) * pow ( 6.0 - 10.0 * i*dx, 2 );
        } else if (std::strcmp(argv[1], "sin") == 0)
        {
            T[0][i] = sin(i*dx);
        } else if (std::strcmp(argv[1], "quadratic") == 0)
        {
            T[0][i] = exp(-80.0* (i*dx-8)*(i*dx-8));
        }
        else {
            std::cerr << "Incorrect argument. only gaussian, sin, or quadratic values are allowed";
            return 1;
        }
    }
    
    for (int i= 1; i<= nt; i++)
    {
        for (int j = 1; j< 2*nx; j++)
        {
            r[j-1]=(1.0-2.0*sigma)*T[i-1][j] + sigma*(T[i-1][j+1] + T[i-1][j-1]);
        }
        triDiag(1.0 + 2.0*sigma, -sigma, -sigma, r, x, 0);
        for (int j = 1; j< 2*nx; j++)
        {
            T[i][j] = x[j-1];
        }
        if(i%50 == 0)
        {
            string outPath = "dataFiles/results_"+to_string(i)+".dat";
            ofstream outFile(outPath);

            // Check if the file was successfully opened
            if (outFile.is_open()) {
                for (int k=0; k < 2*nx+1; k++)
                {
                    double val = (double)(k+1)/2.0;
                    std::snprintf(buffer, sizeof(buffer), "%.1f    %.15e", val, T[i][k]);

                    outFile.precision(15);
                    outFile << buffer << std::endl;
                }
                outFile.close();
            } else {
                std::cerr << "Error: Unable to open or create file in directory: " << outPath << std::endl;
                std::cerr << "Ensure the 'dataFiles' directory exists and you have write permissions." << std::endl;
                return 1;
            }
        }
    }

    return 0;
}