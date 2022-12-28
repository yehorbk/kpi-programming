# express api
This is just a simple CRUD API of Books made with Express.

To start it, install Node and run:

```
npm install
npm start
```

The application checks 2 environment variables:
* `PORT` - optional port to listen, default is `3000`
* `BASE_URL` - base path to backend API, must be specified as `http://<HOST_NAME>:<PORT>/api`, default is `http://localhost:8080/api`