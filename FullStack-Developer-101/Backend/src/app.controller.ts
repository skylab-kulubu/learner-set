import {
  Controller,
  Delete,
  Get,
  Patch,
  Post,
  Query,
  Req,
} from '@nestjs/common';
import { AppService } from './app.service';

interface Todo {
  task: string;
  isDone: boolean;
}

@Controller()
export class AppController {
  Todos: Todo[] = [
    {
      task: 'Learn NestJS',
      isDone: false,
    },
    {
      task: 'Learn TypeScript',
      isDone: false,
    },
    {
      task: 'Learn GraphQL',
      isDone: false,
    },
  ];

  constructor(private readonly appService: AppService) {}

  @Get()
  getHello(): string {
    return this.appService.getHello();
  }

  @Get('/test')
  getTest(@Query('testName') testName: string): string {
    return this.appService.getTest(testName);
  }

  @Get('/getMyTodo')
  getMyTodo(): Todo[] {
    console.log('getMyTodo');
    return this.Todos;
  }

  @Post('/addTodo')
  addTodo(@Query('task') task: string): Todo {
    const newTodo: Todo = {
      task,
      isDone: false,
    };
    this.Todos.push(newTodo);
    return newTodo;
  }

  @Delete('/deleteTodo')
  deleteTodo(@Query('task') task: string): Todo[] {
    const index = this.Todos.findIndex((todo) => todo.task === task);
    this.Todos.splice(index, 1);
    return this.Todos;
  }

  @Patch('/updateTodo')
  updateTodo(
    @Query('task') task: string,
    @Query('isDone') isDone: boolean,
  ): Todo[] {
    const index = this.Todos.findIndex((todo) => todo.task === task);
    this.Todos[index].isDone = isDone;
    return this.Todos;
  }
}
