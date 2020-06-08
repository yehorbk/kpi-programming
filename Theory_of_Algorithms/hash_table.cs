using System;
using System.Collections.Generic;

namespace lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = { 30, 19, 9, 15, 55, 24, 3, 78, 46, 41, 30, 0 };
            int s = 79;

            HashTable_Chain hashTable_Chain = new HashTable_Chain();
            hashTable_Chain.prepareArray(array);
            // Console.WriteLine(hashTable.ToString());
            Console.WriteLine("Get: " + hashTable_Chain.get(s.ToString()));
            Console.WriteLine("Collisions count: " + hashTable_Chain.collisionsCount);
            Console.WriteLine();

            HashTable_Indexing hashTable_Indexing = new HashTable_Indexing();
            hashTable_Indexing.prepareArray(array);
            // Console.WriteLine(hashTable.ToString());
            Console.WriteLine("Get: " + hashTable_Indexing.get(s.ToString()));
            Console.WriteLine("Collisions count: " + hashTable_Indexing.collisionsCount);
            Console.WriteLine();
        }
    }
    class HashTable_Chain
    {
        class Item 
        {
            public string key { get; private set; }
            public List<int[]> value { get; private set; }
            public Item (string key, List<int[]> value) {
                this.key = key;
                this.value = value;
            }
            public override string ToString() {
                return this.key + ": " + this.stringifyList(this.value.ToArray());
            }
            private string stringifyList(int[][] array) {
                string result = "[";
                for (int i = 0; i < array.Length; i++) {
                    result += "[" + string.Join(",", array[i]) + "]";
                }
                result += "]";
                return result;
            }
        }
        private List<Item> items;
        public int collisionsCount { get; private set; } = 0;
        public HashTable_Chain() 
        {
            this.items = new List<Item>();
        }
        public void prepareArray(int[] array) 
        {
            for (int i = 0; i < array.Length; i++) {
                for (int j = i + 1; j < array.Length; j++) {
                    int[] value = { array[i], array[j] };
                    string key = this.hash(array[i], array[j]);
                    this.insert(key, value);
                }
            }
        }
        public void insert(string key, int[] value) 
        {
            Item obj = null;
            if ((obj = this.items.Find(x => x.key == key)) != null) 
            {
                this.collisionsCount++;
                obj.value.Add(value);
            } else 
            {
                List<int[]> valuesList = new List<int[]>();
                valuesList.Add(value);
                Item item = new Item(key, valuesList);
                this.items.Add(item);
            }
        }
        public string get(string key) 
        {
            Item item = this.items.Find(x => x.key == key);
            return  item == null ? "No elements found!" : item.ToString();
        }

        public void remove(string key) 
        {
            this.items.Remove(this.items.Find(x => x.key == key));
        }
        private string hash(int a, int b) 
        {
            return (a + b).ToString();
        }
        public override string ToString() 
        {
            return string.Join("\n", this.items);
        }
    }
    class HashTable_Indexing
    {
        class Item 
        {
            public string key { get; private set; }
            public List<int[]> value { get; private set; }
            public Item (string key, List<int[]> value) {
                this.key = key;
                this.value = value;
            }
            public override string ToString() {
                return this.key + ": " + this.stringifyList(this.value.ToArray());
            }
            private string stringifyList(int[][] array) {
                string result = "[";
                for (int i = 0; i < array.Length; i++) {
                    result += "[" + string.Join(",", array[i]) + "]";
                }
                result += "]";
                return result;
            }
        }
        private List<Item> items;
        public int collisionsCount { get; private set; } = 0;
        public HashTable_Indexing() 
        {
            this.items = new List<Item>();
        }
        public void prepareArray(int[] array) 
        {
            for (int i = 0; i < array.Length; i++) {
                for (int j = i + 1; j < array.Length; j++) {
                    int[] value = { array[i], array[j] };
                    string key = this.hash(array[i], array[j]);
                    this.insert(key, value);
                }
            }
        }
        public void insert(string key, int[] value) 
        {
            Item obj = null;
            if ((obj = this.items.Find(x => x.key == key)) != null) 
            {
                this.collisionsCount++;
                this.insert(key + "0", value);
            } else 
            {
                List<int[]> valuesList = new List<int[]>();
                valuesList.Add(value);
                Item item = new Item(key, valuesList);
                this.items.Add(item);
            }
        }
        public string get(string key) 
        {
            Item item = this.items.Find(x => x.key == key);
            return  item == null ? "No elements found!" : item.ToString();
        }

        public void remove(string key) 
        {
            this.items.Remove(this.items.Find(x => x.key == key));
        }
        private string hash(int a, int b) 
        {
            return (a + b).ToString();
        }
        public override string ToString() 
        {
            return string.Join("\n", this.items);
        }
    }
}
