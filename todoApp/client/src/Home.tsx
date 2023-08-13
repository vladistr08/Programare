import React, { ChangeEvent, useState, useEffect, useCallback } from "react";
import TodoTask from "./components/TodoTask";
import { ITask } from "./Interfaces";
import Nav from "./components/Nav";
import { addTaskDb, deleteTaskDb, getAllTasks } from "./api";
import { useNavigate, useLocation } from 'react-router-dom';

const Home = () => {

    const location = useLocation()
    const navigate = useNavigate()

    const userId = location.state?.userId
    console.log(userId)

    const [task, setTask] = useState<string>("");
    const [deadline, setDeadline] = useState<string>("");
    const [description, setDescription] = useState<string>("");
    const [priority, setPriority] = useState<number>(0);
    const [completed, setCompleted] = useState<boolean>(false);
    const [todoList, setTodoList] = useState<ITask[]>([]);

    // Load tasks only once when the page is loaded
    useEffect(() => {
        if(userId === undefined)
            navigate("/login")
        else{
            getAllTasks(userId).then((data) => {
                setTodoList(data);
            });
        }
    }, [userId, navigate]);

    const handleChange = useCallback((event: ChangeEvent<HTMLInputElement>): void => {
        const { name, value } = event.target;
        if (name === "task") {
            setTask(value);
        } else if (name === "deadline") {
            setDeadline(value);
        } else if (name === "description") {
            setDescription(value);
        } else if (name === "priority") {
            setPriority(Number(value));
        }
    }, []);

    const addTask = useCallback((): void => {
        addTaskDb({ userId: userId, name: task, dueDate: deadline, description, priority, completed })
            .then((newTask) => {
                setTodoList((prevTodoList) => [...prevTodoList, newTask]);
                setTask("");
                setDeadline("");
                setDescription("");
                setCompleted(false);
                setPriority(0);
            });
    }, [task, deadline, description, priority, completed]);

    const deleteTask = useCallback((taskId: string): void => {
        deleteTaskDb(taskId).then((isDeleted) => {
            if (isDeleted) {
                setTodoList((prevTodoList) => prevTodoList.filter((task) => task.todoId !== taskId));
                window.location.reload()
            } else {
                console.log("Nopeeee");
                //toast
            }
        });
    }, []);
    return (
        <div className="App background indigo lighten-5">
            <Nav userId={userId}/>
            <div className="row">

            </div>
            <div className="row">

            </div>
            <div className="header indigo lighten-2 container z-depth-4">
                <div className="container center">
                    <input
                        type="text"
                        placeholder="Task Name..."
                        name="task"
                        value={task}
                        onChange={handleChange}
                    />
                    <div className="row">
                        <input
                            type="date"
                            name="deadline"
                            className="col s6 datepicker"
                            placeholder="Enter the deadline in format xxxx-xx-xx..."
                            value={deadline}
                            onChange={handleChange}
                        />
                        <div className="col s1"></div>
                        <input
                            name="priority"
                            type="number"
                            className="col s5 left"
                            placeholder="Priority level"
                            value={priority}
                            onChange={handleChange}
                        />
                    </div>

                    <input
                        type="text"
                        name="description"
                        placeholder="Enter a description..."
                        value={description}
                        onChange={handleChange}
                    />
                    <button className="btn background indigo darken-2 black-text" onClick={addTask}>Add Task</button>
                    <div className="row "></div>
                    <div className="row "></div>
                </div>
            </div>
            <div className="todoList container center">
                {todoList.map((task: ITask, key: number) => {
                    return <TodoTask key={key} task={task} deleteTask={deleteTask} />;
                })}
            </div>
        </div>
    );
};

export default Home;