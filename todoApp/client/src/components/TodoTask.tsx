import React, {ChangeEvent, useState} from "react";
import { ITask } from "../Interfaces";

interface Props {
    task: ITask;
    deleteTask(taskId: string): void;
}

const TodoTask = ({ task, deleteTask }: Props) => {
    const [completed, setCompleted] = useState<boolean>(task.completed)
    const handleChange = (e: ChangeEvent<HTMLInputElement>) => {
        setCompleted(e.target.checked)
        task.completed = !task.completed
        //update in db
    }
    return (
        <div className="container section">
            <div className="row hoverable indigo darken-1">
                <div className="col s8">
                    <h5 className="text-darken-4 ">Task: {task.name}</h5>
                </div>
                <div className="col s2 background">
                    <p className="text-darken-4"><b>Deadline:</b> {task.dueDate}</p>
                </div>
                <div className="col s2 center">
                    <button
                        className="waves-effect btn-flat large black-text background deep-orange darken-3 right"
                        onClick={() => {
                            deleteTask(task.todoId);
                        }}
                    >
                        X
                    </button>
                </div>
                <div className="col s12 center indigo lighten-3">
                    <p><b>Description:</b> {task.description}</p>
                </div>
                <div className="col s6 right-align">
                    <p><b>Priority:</b> {task.priority}</p>
                </div>
                <div className="col s6 left-align">
                    <p>
                        <label>
                            <input type="checkbox" checked={completed} onChange={handleChange}/>
                            <span className="black-text">Done?</span>
                        </label>
                    </p>
                </div>
            </div>
        </div>
    );
};

export default TodoTask;