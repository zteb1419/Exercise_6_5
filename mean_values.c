#include <stdio.h>
#define P_NUM 5
#define MASK 0b00111111

#define ARMY 1
#define NAVY 2
#define AIRF 3

int main() {
    int age = 0, corps, height;
    int arr[2*P_NUM];

    for(int cnt = 0; cnt < 2*P_NUM; cnt+=2) {
        printf("Input age: ");
        while(scanf("%d", &age) != 1 || age < 17 || age > 40) {
            for ( int ch; (ch = getchar()) != EOF && ch != '\n'; ) { }
            printf("Invalid age! Try again: ");
        }
        printf("Input Corps (1 - 3): ");
        while(scanf("%d", &corps) != 1 || corps < 1 || corps > 3) {
            for ( int ch; (ch = getchar()) != EOF && ch != '\n'; ) { }
            printf("Invalid Corps! Try again: ");
        }
        printf("Input Height in cm: (140 - 220): ");
        while(scanf("%d", &height) != 1 || height < 140 || height > 220) {
            for ( int ch; (ch = getchar()) != EOF && ch != '\n'; ) { }
            printf("Invalid Height! Try again: ");
        }
        /* MSB and MSB-1 bits used for CORPS (eg. Army, Navy, Air Force) */
        arr[cnt] = age | (corps << 6); arr[cnt+1] = height;
        printf("Person %d: \n", 1 + cnt/2);
        printf("Age: %d, height: %d, corps: %d\n\n", age, height, arr[cnt] >> 6 );
        
    }
    int sum_army_ages = 0, sum_navy_ages = 0, sum_airf_ages = 0;
    int sum_army_heights = 0, sum_navy_heights = 0, sum_airf_heights = 0;
    int cnt_army = 0, cnt_navy = 0, cnt_airf = 0;
    
    for(int n = 0; n < 2*P_NUM; n+=2) {
        switch(arr[n] >> 6) {
            case ARMY:
                {
                    sum_army_ages += (arr[n] & MASK);
                    sum_army_heights += arr[n+1];
                    cnt_army++;
                }
            break;
            case NAVY:
                {
                    sum_navy_ages += (arr[n] & MASK);
                    sum_navy_heights += arr[n+1];
                    cnt_navy++; 
                }
            break;
            case AIRF:
                {
                    sum_airf_ages += (arr[n] & MASK);
                    sum_airf_heights += arr[n+1];
                    cnt_airf++;
                }
            break;
        }
    }
    printf("ARMY:\n");
    if(cnt_army > 0) {
        printf("   Mean age: %.1f", (float)sum_army_ages/cnt_army);
        printf("   Mean height: %.1f\n", (float)sum_army_heights/cnt_army);
    } else {
        printf("No army members!\n");
    }
    printf("NAVY:\n");
    if(cnt_navy > 0) {
        printf("   Mean age: %.1f", (float)sum_navy_ages/cnt_navy);
        printf("   Mean height: %.1f\n", (float)sum_navy_heights/cnt_navy);
    } else {
        printf("No navy members!\n");
    }
    printf("AIR FORCE:\n");
    if(cnt_airf > 0) {
        printf("   Mean age: %.1f", (float)sum_airf_ages/cnt_airf);
        printf("   Mean height: %.1f\n", (float)sum_airf_heights/cnt_airf);
    } else {
        printf("No air force members!\n");
    }

}