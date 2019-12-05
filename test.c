#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    static char p;
    static int number;
    if (fork() == 0) /*子进程*/
    {
        p = 'c'; /*子进程对数据的修改*/
        printf("p = %c , number = %d \n ", p, number);
        exit(0);
    }
    /*父进程*/
    number = 14; /*父进程对数据修改*/
    printf("p = %c , number = %d \n ", p, number);
    exit(0);
}

 public int countSubstrings(String s) {
        int len = s.length();
        if(len <= 1) return len;
        boolean[][] dp = new boolean[len][len];
        int i;
        int j;
        int row, column;
        boolean current;
        int count = 0;
        for(i = 0; i < len; i++){
            dp[i][i] = true;
            count++;
        }
        for(i = 1; i < len; i++){
            for(j = 0; j <= len - i - 1; j++){
                row = j;
                column = i + j;
                current = s.charAt(row) == s.charAt(column);
                if(current && (i == 1 || dp[row + 1][column - 1])){
                    dp[row][column] = true;
                    count++;
                }
            }
           
        }
        return count;
    }

作者：glamour-2
链接：https://leetcode-cn.com/problems/palindromic-substrings/solution/dong-tai-gui-hua-yun-xing-shi-jian-11mszhong-xin-k/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 public int countSubstrings(String s) {
        int count = 0;
        int i;
        for(i = 0; i < s.length(); i++){
            count += countPalindrome(s, i, i);
            count += countPalindrome(s, i, i + 1);
        }
         return count;
    }
    public int countPalindrome (String s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.length() && s.charAt(left--) == s.charAt(right++)){
            count++;
        }
        return count;
    }

作者：glamour-2
链接：https://leetcode-cn.com/problems/palindromic-substrings/solution/dong-tai-gui-hua-yun-xing-shi-jian-11mszhong-xin-k/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。