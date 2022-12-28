package cloud.dmytrominochkin.kotlinbe.repo

import cloud.dmytrominochkin.kotlinbe.data.Book
import org.springframework.data.repository.CrudRepository
import org.springframework.data.rest.core.annotation.RepositoryRestResource

@RepositoryRestResource
interface BooksRepository : CrudRepository<Book, Long> {
}