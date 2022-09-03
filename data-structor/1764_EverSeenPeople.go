package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	//os.Stdinから読み込めたデータを[]Byte形でリターンする
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()


	var mapping = map[string]int{}
	var N, M int;
	
	fmt.Fscanln(reader,&N, &M);

	for i := 0; i<N;i++{
		var name string;
		fmt.Fscanln(reader,&name)
		mapping[name]++
	}

	everHearSee :=[]string{}
	for i := 0; i<M;i++{
		var name string
		fmt.Fscanln(reader,&name)

		mapping[name]++

		if(mapping[name] == 2){
			everHearSee = append(everHearSee, name)
		}

	}
	sort.Strings(everHearSee)
	fmt.Fprintln(writer,len(everHearSee))

	for idx, v := range everHearSee{
		if(idx+1 ==len(everHearSee)){
			fmt.Fprint(writer,v)
			break
		}
		fmt.Fprintln(writer,v)
	}

}