import DomainError from "./DomainError";

export enum DomainResponseType {
  success,
  error,
}

export interface DomainResponseValue<T> {
  entity?: T;
  error?: DomainError;
}

export default class DomainResponse<T> {
  constructor(
    readonly type: DomainResponseType,
    readonly entity: T | undefined,
    readonly error: DomainError | undefined
  ) {}

  static createSuccess<T>(entity: T): DomainResponse<T> {
    return new DomainResponse(DomainResponseType.success, entity, undefined);
  }

  static createSuccessEmpty<T>(): DomainResponse<T> {
    return new DomainResponse<T>(
      DomainResponseType.success,
      undefined,
      undefined
    );
  }

  static createError<T>(error: Error): DomainResponse<T> {
    return new DomainResponse<T>(
      DomainResponseType.error,
      undefined,
      DomainError.parse(error)
    );
  }

  static fromError<T>(domainError: DomainError): DomainResponse<T> {
    return new DomainResponse<T>(
      DomainResponseType.error,
      undefined,
      domainError
    );
  }

  isSuccessful(): boolean {
    return this.type === DomainResponseType.success;
  }

  value(): DomainResponseValue<T> {
    switch (this.type) {
      case DomainResponseType.success:
        return { entity: this.entity! };
      case DomainResponseType.error:
        return { error: this.error };
      default:
        throw new Error("Unsupported error");
    }
  }
}
