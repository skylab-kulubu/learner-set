import { Component, OnInit } from '@angular/core';
import { Item } from './models/item';
import { TodoService } from './services/todo.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
})
export class AppComponent implements OnInit {
  title = 'ng-todo';

  job: string = '';
  todos: Item[] = [];

  constructor(private todoService: TodoService) {}

  ngOnInit() {
    console.log('1');
    this.todoService.getTodos().subscribe((todos) => {
      console.log('to', todos);
      this.todos = todos;
    });
    console.log('2');
  }

  removeItem(i: number): void {
    this.todos.splice(i, 1);
  }

  addItem() {
    if (this.job.length == 0) return;

    const item: Item = { task: this.job, isDone: false };

    this.todos.push(item);
    this.job = '';
  }
}
