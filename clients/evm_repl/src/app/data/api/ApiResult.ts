import ApiError from "./ApiError";

interface Success<T> {
  body?: T;
}

interface Failure {
  body: ApiError;
}

type Response<T> = Success<T> | Failure;

class ApiResponse<T> {
  constructor(public response: Response<T>) {}

  isSuccessful(): boolean {
    return this.instanceOfSuccess(this.response);
  }

  private instanceOfSuccess(_value: any): _value is Success<T> {
    return true;
  }

  static success<T>(value?: T): ApiResponse<T> {
    return new ApiResponse<T>({ body: value });
  }

  static error<T>(error: ApiError): ApiResponse<T> {
    return new ApiResponse<T>({ body: error });
  }
}

export { ApiResponse };
