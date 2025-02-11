#include<iostream>
#include <c7x.h>
#include <c7x_scalable.h>
#include <fstream> 
using namespace std;
using namespace c7x;
int main(){
    int padding = 0,input_height = 1, input_width = 32,in_channel = 1 ,out_channel = 1 , kernel_height = 1, kernel_width = 32,stridex =1,stridey = 1;
    {// cout<<"Enter Input Channel : ";
    // cin>>in_channel;
    // cout<<"Enter Output Channel : ";
    // cin>>out_channel;
    // cout<<"Enter Input Height : ";
    // cin>>input_height;
    // cout<<"Enter Input Width : ";
    // cin>>input_width;
    // cout<<"Enter Padding Size : ";
    // cin>>padding;
    // cout<<"Enter Kernel Height : ";
    // cin>>kernel_height;
    // cout<<"Enter Kernel Width : ";
    // cin>>kernel_width;
    // cout<<"Enter Stride(For Column) : ";
    // cin>>stridey;
    // cout<<"Enter Stride(For Row) : ";
    // cin>>stridex;
    }
    int output_height = (((input_height + (2*padding)) - kernel_height) / stridex) + 1;
    int output_width = (((input_width + (2*padding)) - kernel_width) / stridey) + 1;
    cout<<out_channel<<" "<<output_height<<" "<<output_width<<endl;
    int16_t input[in_channel][input_height][input_width] ,output[out_channel][output_height][output_width],filter[out_channel][in_channel][kernel_height][kernel_width];
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
            for(int w = 0;w < input_width;w+=32){
                input_wp[r][padding+c][padding+w] = input[r][c][w];
            }
        }
    }
    int times = 0;
    for(int ch = 0;ch < out_channel;ch++){
        for(int r = 0;r < output_height;r++){
            for(int c = 0;c < output_width;c++){
                
            }
        }
    }
    cout<<"Times : "<<times<<endl;
    ofstream outFile("vector_output.txt");
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