#include <stdio.h>

int main(void) {
        printf("\n");

    int nums[] = {30,-5,-90,11,55,-67};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("Given Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    
    int ans[n]; 
    int evn = 0;
    int odd = 1;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[evn] = nums[i];
            evn += 2;
        } else {
            ans[odd] = nums[i];
            odd += 2;
        }
    }
    
    printf("Rearranged Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}
