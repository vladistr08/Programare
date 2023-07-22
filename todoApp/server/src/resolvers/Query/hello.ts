import {connectToDatabase} from "../../lib/db/CRUD";


export default async (
    _: object,
    __: object
): Promise<string> => {
    await connectToDatabase()
    return "Salutare jupane"
}