#include <iostream>
using namespace std;
int main(){
    int height = 7, width = 7;
    int mat[height][width] = {{1,0,1,9,6,7,9},{2,7,7,5,8,2,5},{7,7,4,8,9,5,1},{3,6,2,9,6,7,3},{3,8,1,9,9,1,3},{2,5,5,8,6,1,5},{2,0,9,1,7,6,0}};
    int kernel_height = 3, kernel_width = 3;
    int kernel[kernel_height][kernel_width] = {{0,0,1},{-1,0,-1},{0,0,1}};
    int output_height = (height - kernel_height + 1),output_width = (width - kernel_width + 1);;
    int output[output_height][output_width];
    for(int r = 0;r < output_height;r++){
        for(int c = 0;c < output_width;c++){
            int res = 0;
            for(int kr = 0;kr < kernel_height;kr++){
                for(int kc = 0;kc < kernel_width;kc++){
                    res += ( mat[r+kr][c+kc] * kernel[kr][kc]);
                }
            }
            output[r][c] = res;
            cout<<output[r][c]<<" ";
        }
        cout<<endl;
    }
}