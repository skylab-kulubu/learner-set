import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Item } from '../models/item';

@Injectable({ providedIn: 'root' })
export class TodoService {
  constructor(private http: HttpClient) {}

  getTodos() {
    return this.http.get<Item[]>(`http://localhost:3000/getMyTodo`);
  }
}
