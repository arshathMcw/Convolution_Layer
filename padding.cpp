#include<iostream>
#include <fstream> 
using namespace std;
int main(){
    int padding = 2;
    int input_height = 7, input_width = 7,in_channel = 2,out_channel = 1 , kernel_height = 3, kernel_width = 3 ,output_height = ((input_height + (2*padding)) - kernel_height) + 1,output_width = ((input_width + (2*padding)) - kernel_width) + 1;
    int input[in_channel][input_height][input_width] ,output[out_channel][output_height][output_width],filter[out_channel][in_channel][kernel_height][kernel_width];
    for(int r = 0;r < in_channel;r++){
        for(int c = 0;c < input_height;c++){
            for(int w = 0;w < input_width;w++){
                input[r][c][w] = r + c + w;
            }
        }
    }
    for(int p = 0;p < out_channel;p++){
        for(int r = 0;r < in_channel;r++){
            for(int c = 0;c < kernel_height;c++){
                for(int w = 0;w < kernel_width;w++){
                    filter[p][r][c][w] = p + r + c + w;
                }
            }
        }
    }
    // Padding
    int m_input_height = input_height + (2 * padding);
    int m_input_width = input_width + (2 * padding);
    int input_wp[in_channel][m_input_height][m_input_width];
    for(int r = 0;r < in_channel;r++){
        for(int c = 0;c < m_input_height;c++){
            for(int w = 0;w < m_input_width;w++){
                input_wp[r][c][w] = 0;
            }
        }
    }
    for(int r = 0;r < in_channel;r++){
        for(int c = 0;c < input_height;c++){
            for(int w = 0;w < input_width;w++){
                input_wp[r][padding+c][padding+w] = input[r][c][w];
            }
        }
    }
    for(int ch = 0;ch < out_channel;ch++){
        for(int r = 0;r < output_height;r++){
            for(int c = 0;c < output_width;c++){
                int res = 0;
                for(int cch = 0;cch < in_channel;cch++){
                    for(int rr = 0;rr < kernel_height;rr++){
                        for(int cc = 0;cc < kernel_width;cc++){
                            res += (input_wp[cch][r+rr][c+cc] * filter[ch][cch][rr][cc]);
                        }
                    }
                }
                output[ch][r][c] = res;
            }
        }
    }
    ofstream outFile("matrix_output.txt");
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    for(int ch = 0;ch < out_channel;ch++){
        for(int r = 0;r < output_height;r++){
            for(int c = 0;c < output_width;c++){
                outFile<<output[ch][r][c]<<" ";
            }
            outFile<<endl;
        }
        outFile<<endl;
    }
}

