import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  getHello(): string {
    return 'Hello World!';
  }

  getTest(testName: string): string {
    return `Hello ${testName}!`;
  }

  getMyTodo(req: any): string {
    return `Hello ${req.query.testName}!`;
  }
}
