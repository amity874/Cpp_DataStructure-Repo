import java.awt.*;
import java.util.*;
class Node<T>{
    String key;
    T value;//values will be generic
    Node<T> next;
    Node(String key ,T value){
        this.key=key;
        this.value=value;
        this.next=null;
    }
}
public class Hashing<T>{
    int cs;//currrent size//use for load factor//
    int ts;//total size//use for load factor//
    private Node<T> Arr[];//Array of linked list
    Hashing(int ts){//constructor
        this.cs =0;
        this.ts=ts;
        Arr=new Node[this.ts];
        for (int i=0;i<this.ts ;i++ ) {
            Arr[i]=null;
        }
    }
    public int HashFunction(String key){
        //this return the bucket function
        int sum=0;
        int factor=1;
        for (int i=0;i<key.length();i++) {
            sum=(sum%this.ts)+((int)key.charAt(i)*factor)%this.ts;
            sum=sum%this.ts;
            factor=((factor%this.ts)*(37%this.ts))%this.ts;
        }
        return (int) sum;
    }
    public void Rehash(){
        int oldsize=this.ts;
        this.ts=2*oldsize;
        Node<T>oldtable[]=this.Arr;
        this.Arr=new Node[this.ts];
        for (int i=0;i<this.ts;i++){
            this.Arr[i]=null;
        }
        for (int i=0;i<oldsize;i++){
            Node<T>temp=oldtable[i];
            while (temp!=null){
                Insert(temp.key,temp.value);
                temp=temp.next;
            }
        }
    }
    public void Insert(String key,T value){
        int bi=HashFunction(key);//bi bucket index
        T result=Search(key);
        if(result!=null){
        	Node<T> temp=this.Arr[bi];
        	while (temp!=null){
        		if(temp.key==key){
        			temp.value=value;
        		}
        		temp=temp.next;
        	}
        	return;
        }

        Node<T> new_node=new Node<>(key,value);
        if(this.Arr[bi]==null){
            this.Arr[bi]=new_node;
        }
        else {
            //Collision
            new_node.next=this.Arr[bi];
            this.Arr[bi]=new_node;
        }
        this.cs++;
        double loadfactor=(double) (this.cs)/(this.ts);
        if(loadfactor>0.5){
            Rehash();
        }
    }
    public T Search(String key){
        int idx=HashFunction(key);
        Node<T>temp=this.Arr[idx];
        while (temp!=null){
            if(temp.key==key)return temp.value;
            temp=temp.next;
        }
        return null;
    }
    public void Display(){
        for (int i=0;i<this.ts;i++){
            Node<T>temp=this.Arr[i];
            if(temp==null){
                System.out.println("Empty");
            }
            while (temp!=null){
                System.out.println("("+temp.key+","+temp.value+") ->");
                temp=temp.next;
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Hashing<Integer>hashtable=new Hashing<>(2);
        while (n-->0){
            String key;
            int value;
            key=sc.next();
            value=sc.nextInt();
            hashtable.Insert(key,value);
        }
        hashtable.Display();
    }
}