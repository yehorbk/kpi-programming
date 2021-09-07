package main

import "net/http"
import "gotest/books"

func main() {
  http.HandleFunc("/books", books.Handler)
  http.ListenAndServe(":3000", nil)
}
