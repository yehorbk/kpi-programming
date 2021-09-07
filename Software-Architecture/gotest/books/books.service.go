package books

var booksList = []*Book{}

func findById(id int) *Book {
  if (id < 0 || id > len(booksList)) {
    return nil
  }
  return booksList[id]
}

func create(book Book) *Book {
  book.Id = len(booksList)
  booksList = append(booksList, &book)
  return &book
}

func update(id int, book Book) *Book {
  if (id < 0 || id > len(booksList)) {
    return nil
  }
  bookDb := booksList[id]
  if (bookDb != nil) {
    bookDb.Title = book.Title
    bookDb.Author = book.Author
  }
  return bookDb
}

func delete(id int) {
  if (id < 0 || id > len(booksList)) {
    return
  }
  booksList[id] = nil
}

func findAll() []*Book {
  return booksList
}

