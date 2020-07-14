#include "ZPrint.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int ClipPrint(const std::vector<std::vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();
    int *p_log = (int *)malloc(m*n*sizeof(int));
    if (!p_log) {
        cout << "malloc fail!" << endl; 
        return -1; 
    }
    memset(p_log, 0, m*n*sizeof(int));
    bool stop = false;
    int cur_i = 0;
    int cur_j = 0;
    int t_left = 0;
    int t_down = 0;
    int t_right = 0;
    int t_up = 0;
    //
    int z_count = 0; //记录走了几个回
    while (!stop) {	 
        // 每一趟走一个回 
        // 一横
        if (1 == p_log[cur_i*n+cur_j]) {
            cout << endl;
            cout << "this point " << cur_i << "\t" << cur_j << " had print" << endl; 
            stop = true;
            break;
        } else {
            // print and turn right 
            while (cur_j < n) {
                // 打印直到遇到打印过的 
                if (0 == p_log[cur_i*n+cur_j]) {
                    std::cout << arr[cur_i][cur_j] << " ";
                    p_log[cur_i*n+cur_j] = 1;
                    ++cur_j;
                } else {
                    break; 
                }
            }
            ++t_right;
        }
        // 向下的一竖
        // cur_j一定要回退1
        --cur_j;
        ++cur_i;
        if (cur_i >= m) {
            cout << endl;
            std::cout << "row end " << endl;
            stop = true;
            break; 
        }
        if (1 == p_log[cur_i*n+cur_j]) {
            cout << endl;
            cout << "this point " << cur_i << "\t" << cur_j << " had print" << endl; 
            stop = true;
            break;
        } else {
            while (cur_i < m) {
                if (0 == p_log[cur_i*n+cur_j]) {
                    std::cout << arr[cur_i][cur_j] << " ";
                    p_log[cur_i*n+cur_j] = 1;
                    ++cur_i;
                } else {
                    break; 
                }
            }
            ++t_down;
        }
        // 向左
        // cur_i 回退1
        --cur_i;
        --cur_j;
        if (cur_j < 0) {
            cout << endl;
            std::cout << "col end " << endl;
            stop = true;
            break; 
        }

        if (1 == p_log[cur_i*n+cur_j]) {
            cout << endl;
            cout << "this point " << cur_i << "\t" << cur_j << " had print" << endl; 
            stop = true;
            break;
        } else {
            while (cur_j >= 0) {
                if (0 == p_log[cur_i*n+cur_j]) {
                    std::cout << arr[cur_i][cur_j] << " ";
                    p_log[cur_i*n+cur_j] = 1;
                    --cur_j;
                } else {
                    break; 
                }
            }
            ++t_left;
        }
        //向上
        //cur_j回退1
        --cur_i;
        ++cur_j;
        if (cur_i < 0) {
            cout << endl;
            std::cout << "row end " << endl;
            stop = true;
            break; 
        }
        if (1 == p_log[cur_i*n+cur_j]) {
            cout << endl;
            cout << "this point " << cur_i << "\t" << cur_j << " had print" << endl; 
            stop = true;
            break;
        } else {
            while (cur_i >= 0) {
                if (0 == p_log[cur_i*n+cur_j]) {
                    std::cout << arr[cur_i][cur_j] << " ";
                    p_log[cur_i*n+cur_j] = 1;
                    --cur_i;
                } else {
                    break; 
                }
            }
            ++t_up;
        }
        //再准备向左的数据 cur_i 回退
        ++cur_i;
        ++cur_j;
        if (cur_j >= n) {
            cout << endl;
            std::cout << "col end " << endl;
            stop = true;
            break; 
        }

        ++z_count;
    }
    std::cout << endl;
    std::cout << "z_count " << z_count << " left " << t_left << " down " << t_down << " right " << t_right << " up " << t_up << endl;


    free(p_log);
    return z_count;
}


