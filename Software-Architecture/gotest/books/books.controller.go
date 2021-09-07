package books

import "fmt"
import "strconv"
import "encoding/json"
import "net/http"

func handleGet(w http.ResponseWriter, r *http.Request) {
  idString := r.URL.Query().Get("id")
  if (idString != "") {
    id, err := strconv.Atoi(idString)
    if (err != nil) {
      http.Error(w, err.Error(), http.StatusBadRequest)
      return
    }
    result := findById(id)
    encoded, err := json.Marshal(result)
    if (err != nil) {
      http.Error(w, err.Error(), http.StatusInternalServerError)
      return
    }
    fmt.Fprintf(w, string(encoded))
  } else {
    result := findAll()
    encoded, err := json.Marshal(result)
    if (err != nil) {
      http.Error(w, err.Error(), http.StatusInternalServerError)
      return
    }
    fmt.Fprintf(w, string(encoded))
  }
}

func handlePost(w http.ResponseWriter, r *http.Request) {
  var book Book
  err := json.NewDecoder(r.Body).Decode(&book)
  if (err != nil) {
    http.Error(w, err.Error(), http.StatusBadRequest)
    return
  }
  result := create(book)
  encoded, err := json.Marshal(result)
  if (err != nil) {
    http.Error(w, err.Error(), http.StatusInternalServerError)
    return
  }
  fmt.Fprintf(w, string(encoded))
}

func handlePut(w http.ResponseWriter, r *http.Request) {
  idString := r.URL.Query().Get("id")
  if (idString == "") {
    http.Error(w, "id parameter required", http.StatusBadRequest)
  }
  id, err := strconv.Atoi(idString)
  if (err != nil) {
    http.Error(w, err.Error(), http.StatusBadRequest)
  }
  var book Book
  err = json.NewDecoder(r.Body).Decode(&book)
  if (err != nil) {
    http.Error(w, err.Error(), http.StatusBadRequest)
    return
  }
  result := update(id, book)
  encoded, err := json.Marshal(result)
  if (err != nil) {
    http.Error(w, err.Error(), http.StatusInternalServerError)
    return
  }
  fmt.Fprintf(w, string(encoded))
}

func handleDelete(w http.ResponseWriter, r *http.Request) {
  idString := r.URL.Query().Get("id")
  if (idString == "") {
    http.Error(w, "id parameter required", http.StatusBadRequest)
  }
  id, err := strconv.Atoi(idString)
  if (err != nil) {
      http.Error(w, err.Error(), http.StatusBadRequest)
  }
  delete(id)
  w.WriteHeader(200)
}

func Handler(w http.ResponseWriter, r *http.Request) {
  switch r.Method {
    case "GET":
      handleGet(w, r)
    case "POST":
      handlePost(w, r)
    case "PUT":
      handlePut(w, r)
    case "DELETE":
      handleDelete(w, r)
  }
}
