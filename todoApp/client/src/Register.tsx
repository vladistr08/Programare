import React, {FC, useState} from 'react'
import {registerUser} from "./api";
import {Link, Outlet, useNavigate} from "react-router-dom";

export const Register: FC = () => {

    const navigate = useNavigate()

    const [username, setUsername] = useState<string>('')
    const [password, setPassword] = useState<string>('')
    const [email, setEmail] = useState<string>('')

    const handleLogin = async () => {
        const result = await registerUser(username, password, email)
        console.log(result)
        if(result === undefined)
            navigate("/register") //toast
        else
            navigate("/home", {state: {
                    userId: result
                }})
    }

    return (
        <>
            <div>
                <div className="section"></div>
                <main>
                    <center>
                        <div className="section"></div>

                        <h5 className="indigo-text">Please, login into your account</h5>
                        <div className="section"></div>

                        <div className="container">
                            <div className="z-depth-1 indigo lighten-5 row">

                                <form className="col s12" method="post">
                                    <div className='row'>
                                        <div className='col s12'>
                                        </div>
                                    </div>

                                    <div className='row'>
                                        <div className='input-field col s12'>
                                            <input
                                                placeholder="Enter your username"
                                                className='input' type='text'
                                                name='username'
                                                id='username'
                                                onChange={(e) => {setUsername(e.target.value)}}
                                            />
                                        </div>
                                    </div>

                                    <div className='row'>
                                        <div className='input-field col s12'>
                                            <input
                                                placeholder="Enter your password"
                                                className='input'
                                                type='password'
                                                name='password'
                                                id='password'
                                                onChange={(e) => {setPassword(e.target.value)}}
                                            />
                                        </div>
                                    </div>

                                    <div className='row'>
                                        <div className='input-field col s12'>
                                            <input
                                                placeholder="Enter your email"
                                                className='input'
                                                type='email'
                                                name='email'
                                                id='email'
                                                onChange={(e) => {setEmail(e.target.value)}}
                                            />
                                        </div>
                                    </div>

                                    <br/>

                                    <center>
                                        <div className='row center'>
                                            <div className="col s4 section"></div>
                                            <button type='button' name='btn_register' onClick={handleLogin}
                                                    className='col s4 btn btn-large waves-effect indigo'>Register
                                            </button>
                                            <div className="col s4 section"></div>
                                        </div>
                                    </center>
                                </form>
                            </div>
                        </div>
                        <Link to='/login'>Login</Link>

                    </center>

                    <div className="section"></div>
                    <div className="section"></div>
                </main>
            </div>
            <Outlet/>
        </>

    )
}