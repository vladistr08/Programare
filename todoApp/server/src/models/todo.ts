import mongoose, { Schema } from 'mongoose'
import { v4 as uuidv4 } from 'uuid'

export interface ITodo {
    todoId?: string
    name: string
    description?: string
    dueDate?: string
    priority?: number
}

export const TodoSchema: Schema<ITodo> = new Schema({
    todoId: {type: Schema.Types.UUID, default: () => uuidv4(), unique: true},
    name: {type: String, required: true, unique: true},
    description: String,
    dueDate: String,
    priority: Number
    //subTodos?: ITodo[]
})

export const Todo = mongoose.model<ITodo>('Todo', TodoSchema, 'todos')