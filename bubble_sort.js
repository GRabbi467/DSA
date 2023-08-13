const bubble_sort =(arr,myCallback)=>{
    for(let i = 0 ; i < arr.length ; i++){
        for(let j = 0 ; j <arr.length -i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                [arr[j],arr[j+1]] =  [arr[j+1],arr[j]];
            }
        }
    }
    if(myCallback) myCallback(arr)
    return arr;
}
const x = bubble_sort([8,2,4,1,5,3],function(arr){
    console.log(arr)
});
