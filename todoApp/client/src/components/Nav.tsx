import React from 'react';
import {Link} from "react-router-dom";

interface Props{
    userId: string
}

const Nav = ({userId}: Props) => {

    return (
        <nav>
            <div className="nav-wrapper indigo darken-3 ">
                <a href="#" className="brand-logo right">The true and only Task Manager</a>
                <ul id="nav-mobile" className="left hide-on-med-and-down">
                    <li><Link to="/login">Login</Link></li>
                    <li><Link to="/Register">Register</Link></li>
                    <li><Link to="/Home" state={{userId: userId}}>Home</Link></li>
                </ul>
            </div>
        </nav>
    )
}

export default Nav;